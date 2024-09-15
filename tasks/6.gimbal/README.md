# 任务六：云台控制 - 驱动 CAN 总线电机/姿态解算/PID 控制器

## 📃 任务描述

根据 IMU 的数据驱动云台电机，让一台步兵机器人死死盯住一个方向！

![](./assets/1.gif)

## 🎯 任务目标

1. 驱动 CAN 总线电机、获取电机反馈信息：让一个 GM6020 云台电机转起来，并且顺利接收它反馈回来的信息，如位置、转速等等

2. 使用 PID 控制器控制电机的位置：类比参考资料里 PID 课程提到的”控制无人机高度“的例子，使用附录里给出的 PID 控制器来控制 GM6020 电机的位置

3. 获取 IMU 数据、姿态解算：读取 C 板上板载的 BMI088 IMU 的陀螺仪和加速度计数据，自行选择合适的姿态解算算法获取云台姿态的三个欧拉角

4. 完成云台控制：以解算出的姿态数据作为参考，转动云台上的 yaw 轴电机和 pitch 轴电机，不管底盘如何运动或者受到什么扰动，都让云台稳稳地朝向一个固定的方向

## 🔗 参考资料

- [GM6020 云台电机 使用说明书](https://rm-static.djicdn.com/tem/17348/RoboMaster%20GM6020直流无刷电机使用说明20231013.pdf)

- [RoboMaster 开发板 C 型用户手册](https://rm-static.djicdn.com/tem/35228/RoboMaster%20%20开发板%20C%20型用户手册.pdf)

- [通俗易懂的 PID 控制算法讲解](https://www.bilibili.com/video/BV1et4y1i7Gm)

- [RoboMaster/Development-Board-C-Examples](https://github.com/RoboMaster/Development-Board-C-Examples)

## 附录

### PID 控制器实现

```c
typedef struct {
    double kp;  // 比例系数
    double ki;  // 积分系数
    double kd;  // 微分系数
    double previous_error;  // 上一次误差
    double integral;  // 积分累积
    double output;    // 输出
} pid_t;

void PidInit(pid_t *pid, double kp, double ki, double kd) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->previous_error = 0.0;
    pid->integral = 0.0;
}

void PidUpdate(pid_t *pid, double setpoint, double measured_value, double dt) {
    double error = setpoint - measured_value;
    pid->integral += error * dt;
    double derivative = (error - pid->previous_error) / dt;
    double output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
    pid->previous_error = error;
    pid->output = output;
}
```
