from flask import Flask, jsonify
from flask_cors import CORS
import global_var

app = Flask(__name__)
CORS(app)  # 启用跨源资源共享

@app.route('/api/temperature', methods=['GET'])
def get_temperature():
    # 从全局变量中获取当前温度和其他系统状态信息
    current_temp = global_var.temp_list[-1] if global_var.temp_list else None
    return jsonify({
        "current_temperature": current_temp, # 当前温度
        "set_temperature": global_var.data.get('set_temp'), # 设定温度
        "temp_control_deviation": global_var.data.get('temp_control'), # 温度控制偏差
        "mach_statu": global_var.mach_statu, # 机器状态
        "temperature_history": global_var.temp_list[-10:],  # 返回最近10次温度记录
        "statu": global_var.statu[:10] # 抽屉状态
    })

def run_flask_app():
    # 启动 Flask 应用，设置 debug 模式为 False，禁用重新加载以避免线程问题
    app.run(debug=False, use_reloader=False)