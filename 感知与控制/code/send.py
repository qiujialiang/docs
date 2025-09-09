from struct import pack
import serial
import crcmod

# 全局变量
frame_num = 0  # 帧号
# CRC16 校验算法
crc16 = crcmod.mkCrcFun(0x18005, initCrc=0xFFFF, xorOut=0x0000)
# 数据封装成帧
def packet_data_to_frame(addr, func_num, data):
    global frame_num
    frame_head = pack('2B', 255, 255)  # 0xFFFF 帧头，用于标识帧的开始
    frame_length = pack('B', len(data) + 10)  # 帧长，包括固定部分和数据部分的总长度
    num = pack('B', frame_num)  # 帧号，用于标识帧的顺序
    address = pack('B', addr)  # 设备地址，目标控制板的地址
    fc_num = pack('B', func_num)  # 功能码，表示该帧的功能（如查询、控制等）
    # 计算 CRC 校验值，确保数据传输的可靠性
    crc_check_bytes = frame_length + num + address + fc_num + data
    crc_frame = pack('H', crc16(crc_check_bytes))
    frame_tail = pack('2B', 255, 247)  # 0xFFF7 帧尾，用于标识帧的结束
    # 组装完整的帧
    frame_packet = frame_head + frame_length + num + address + fc_num + data + crc_frame + frame_tail
    frame_num = (frame_num + 1) % 256  # 帧号循环递增
    return frame_packet

# 1. 查询帧(10Byte)
def query_frame(addr):
    return packet_data_to_frame(addr, 1, b'')  # 功能号 1 表示查询帧，无数据部分

# 2. 启停压缩机控制帧(11Byte)
def compressor_control_frame(addr, compressor_control_data):
    control_byte = pack('B', 1 if compressor_control_data else 0)  # 1 表示启动压缩机，0 表示停止
    return packet_data_to_frame(addr, 2, control_byte)  # 功能号 2 表示压缩机控制帧

# 3. 开锁帧(12Byte)
def box_control_frame(addr, box_control_data):
    byte1 = 0
    byte2 = 0
    # 将抽屉开关状态转换为两个字节的数据
    for i in range(8):
        byte1 += box_control_data[i] * (2 ** i)
    for i in range(8, 12):
        byte2 += box_control_data[i] * (2 ** (i - 8))
    return packet_data_to_frame(addr, 3, pack('2B', byte1, byte2))  # 功能号 3 表示开锁帧

# 4. 设置温度帧(11Byte)
def set_temperature_frame(addr, set_temperature_data):
    temp = temp_convert(set_temperature_data)  # 将温度值转换为特定的字节格式
    return packet_data_to_frame(addr, 4, pack('B', temp))  # 功能号 4 表示设置温度帧

# 5. 设置参数帧(28Byte)
def set_parameter_frame(addr, set_parameter_data):
    # 按照参数格式定义组装参数数据
    dev_id = int(set_parameter_data['dev_code'], 16).to_bytes(5, 'big')
    dev_addr = pack('B', set_parameter_data['dev_addr'])
    time_gap = pack('B', set_parameter_data['time_gap'])
    compressor_delay = pack('B', set_parameter_data['compressor_delay'])
    set_temp = pack('B', temp_convert(set_parameter_data['set_temp']))
    temp_control = pack('B', set_parameter_data['temp_control'])
    # 功能号 5 表示设置参数帧
    data = dev_id + dev_addr + b'\x00' + time_gap + compressor_delay + b'\x00\x00' + set_temp + temp_control + b'\xFF\xFF\xFF\xFF\x00'
    return packet_data_to_frame(addr, 5, data)

# 6. 设置温度控制偏差帧(11Byte)
def set_temperature_control_deviation_frame(addr, set_temperature_control_deviation_data):
    return packet_data_to_frame(addr, 6, pack('B', set_temperature_control_deviation_data))  # 功能号 6 表示设置温度控制偏差帧

# 7. 设置设备地址帧(16Byte)
def set_device_address_frame(addr, dev_code_data):
    dev_code_bytes = int(dev_code_data, 16).to_bytes(5, 'big')  # 将设备编码转换为字节
    new_addr = pack('B', addr)  # 新的设备地址
    return packet_data_to_frame(addr, 9, dev_code_bytes + new_addr)  # 功能号 9 表示设置设备地址帧

# 温度值处理
def temp_convert(set_temperature_data):
    set_temperature_data = float(set_temperature_data)
    s = str(set_temperature_data).split('.')
    add_bit1 = '0'  # 整数部分的符号位
    add_bit2 = '0'  # 小数部分的符号位
    if int(s[0]) < 0:
        add_bit1 = '1'
    num1 = abs(int(s[0]))  # 整数部分取绝对值
    num2 = int(s[1]) if len(s) > 1 else 0  # 小数部分，默认为 0
    if num2 >= 5:
        add_bit2 = '1'
    # 将整数部分转换为二进制字符串并补齐到 6 位
    res = bin(num1)[2:] if num1 != 0 else '0'
    res = '0' * (6 - len(res)) + res
    res = add_bit1 + res + add_bit2  # 组合符号位和数值位
    return int(res, 2)  # 转换为整数

# 初始化串口
def init_serial(port='COM2', baudrate=38400):
    return serial.Serial(port, baudrate, timeout=1)  # 初始化串口，设置端口、波特率和超时时间

# 发送帧
def send_frame(frame, com, ui=None):
    com.write(frame)  # 通过串口发送帧
    # 提取帧的关键信息用于日志记录
    frame_info = {
        'length': len(frame),  # 帧的总长度
        'frame_number': frame[3],  # 帧号位于第 5 个字节
        'dev_addr': frame[4],  # 设备地址位于第 6 个字节
        'func_code': frame[5],  # 功能码位于第 7 个字节
        # 数据段（去掉头部、帧长、帧号、地址、功能码和 CRC 校验部分）
        'data': ' '.join(f'{byte:02X}' for byte in frame[6:-4]),
        # CRC 校验位计算范围为帧长 + 帧号 + 地址 + 功能码 + 数据部分
        'checksum': int.from_bytes(frame[-4:-2], byteorder='big')
    }
    print(f"帧已发送: {frame}")  # 打印发送的完整帧用于调试
    if ui is not None:  # 如果提供了用户界面对象，则将帧信息发送给界面进行显示
        ui.log(frame_info)