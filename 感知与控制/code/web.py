from flask import Flask, render_template_string, jsonify
import requests
import threading
import time

app = Flask(__name__)

# 全局变量存储从 API 获取的状态
device_status = {
    "temp_now": None,
    "temp_set": None,
    "compressor": "未知",
    "drawers": [0] * 10,
    "history": []
}

# 后台线程定时请求 API 更新状态
def fetch_device_status():
    while True:
        try:
            # 从本地 API 获取设备状态
            response = requests.get('http://127.0.0.1:5000/api/temperature')
            if response.status_code == 200:
                data = response.json()

                # 更新全局变量中的设备状态
                device_status["temp_now"] = data.get("current_temperature")
                device_status["temp_set"] = data.get("set_temperature")
                device_status["history"] = data.get("temperature_history", [])

                # 解析压缩机状态
                mach_statu = data.get("mach_statu", -1)
                if mach_statu == 0:
                    device_status["compressor"] = "关闭"
                elif mach_statu == 1:
                    device_status["compressor"] = "预启动"
                elif mach_statu == 2:
                    device_status["compressor"] = "启动"
                else:
                    device_status["compressor"] = "故障"

                # 解析抽屉状态
                statu_list = data.get("statu", [])
                if isinstance(statu_list, list) and len(statu_list) >= 10:
                    device_status["drawers"] = statu_list[:10]
                else:
                    device_status["drawers"] = [0] * 10

        except Exception as e:
            print(f"获取设备状态失败: {e}")
            # 如果获取数据失败，设置默认值或错误状态
            device_status.update({
                "temp_now": None,
                "temp_set": None,
                "compressor": "错误",
                "drawers": [0] * 10,
                "history": []
            })

        time.sleep(1)  # 每1秒更新一次数据

@app.route('/')
def index():
    # 渲染HTML模板字符串，返回监控页面
    return render_template_string('''
    <!DOCTYPE html>
    <html lang="zh">
    <head>
        <meta charset="UTF-8">
        <title>设备监控</title>
        <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
        <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
        <style>
            body {
                background-color: #f8f9fa;
            }
            .dashboard-container {
                max-width: 960px;
                margin: auto;
            }
            .temp-card {
                background-color: #0d6efd;
                color: white;
            }
            canvas {
                max-width: 100%;
                height: 300px !important;
            }
            .switch-input {
                transform: scale(1.2);
            }
        </style>
    </head>
    <body>
    <div class="container dashboard-container py-4">
        <h1 class="mb-4 text-center">设备监控系统</h1>

        <!-- 当前状态卡片 -->
        <div class="card temp-card mb-4 shadow-sm">
            <div class="card-body">
                <h5 class="card-title">实时状态</h5>
                <p class="card-text fs-4">当前温度：<strong id="temp-now">--</strong>°C</p>
                <p class="card-text">设定温度：<strong id="temp-set">--</strong>°C</p>
                <p class="card-text">压缩机状态：<strong id="compressor">--</strong></p>
            </div>
        </div>

        <!-- 抽屉状态 -->
        <h2 class="mb-3">抽屉状态</h2>
        <div class="row g-2">
            {% for i in range(10) %}
            <div class="col-md-6 col-lg-4">
                <div class="form-check form-switch d-flex align-items-center">
                    <input class="form-check-input switch-input me-3" type="checkbox" id="drawer{{ i }}" disabled>
                    <label class="form-check-label" for="drawer{{ i }}">抽屉 {{ i+1 }}</label>
                </div>
            </div>
            {% endfor %}
        </div>

        <!-- 温度曲线 -->
        <h2 class="mt-5 mb-3">温度变化曲线</h2>
        <canvas id="temperatureChart" width="600" height="200"></canvas>
    </div>

    <script>
        function updateStatus() {
            $.get('/status', function(data) {
                $('#temp-now').text(data.temp_now !== null ? data.temp_now.toFixed(1) : 'N/A');
                $('#temp-set').text(data.temp_set !== null ? data.temp_set.toFixed(1) : 'N/A');
                $('#compressor').text(data.compressor);

                data.drawers.forEach((state, i) => {
                    $('#drawer' + i).prop('checked', state === 1);
                });

                // 更新图表
                if (window.temperatureChart && data.history.length > 0) {
                    const labels = data.history.map((_, idx) => `${idx + 1}`);
                    window.temperatureChart.data.labels = labels;
                    window.temperatureChart.data.datasets[0].data = data.history;
                    window.temperatureChart.update();
                }
            }).fail(function () {
                $('#temp-now').text('错误');
                $('#temp-set').text('错误');
                $('#compressor').text('错误');
            });
        }

        $(document).ready(function () {
            const ctx = document.getElementById('temperatureChart').getContext('2d');
            window.temperatureChart = new Chart(ctx, {
                type: 'line',
                data: {
                    labels: [],
                    datasets: [{
                        label: '温度变化 (°C)',
                        data: [],
                        fill: true,
                        borderColor: '#0d6efd',
                        backgroundColor: 'rgba(13, 110, 253, 0.1)',
                        tension: 0.3
                    }]
                },
                options: {
                    responsive: true,
                    plugins: {
                        legend: {
                            labels: {
                                font: {
                                    size: 14
                                }
                            }
                        }
                    },
                    scales: {
                        y: {
                            beginAtZero: false,
                            title: {
                                display: true,
                                text: '温度 (°C)'
                            }
                        },
                        x: {
                            title: {
                                display: true,
                                text: '时间步'
                            }
                        }
                    }
                }
            });

            setInterval(updateStatus, 1000);
            updateStatus();  // 页面加载时立即更新一次
        });
    </script>
    </body>
    </html>
    ''')

@app.route('/status')
def status():
    # 返回当前设备状态的 JSON 数据
    return jsonify({
        "temp_now": device_status["temp_now"],
        "temp_set": device_status["temp_set"],
        "compressor": device_status["compressor"],
        "drawers": device_status["drawers"],
        "history": device_status["history"]
    })

if __name__ == '__main__':
    # 在后台启动定时任务，从本地 API 获取数据
    thread = threading.Thread(target=fetch_device_status)
    thread.daemon = True
    thread.start()

    # 启动 Flask Web 服务
    app.run(host='0.0.0.0', port=5001, debug=False)