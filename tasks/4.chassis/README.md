# 任务四：底盘控制 - 驱动 CAN 总线电机/PID 控制器

## 📃 任务描述

驱动一个舵轮底盘进行全向运动。

## 参考步骤

1. 学习驱动 CAN 总线电机：让一个 6020 云台电机转起来，并且顺利接收它反馈回来的信息，如位置、转速等等

2. 学习使用 PID 控制器闭环控制电机角度：类比参考资料里 PID 课程提到的”控制无人机高度“的例子，使用附录里给出的 PID 控制器来控制 6020 电机的位置

3. 学习使用 FreeRTOS：让单片机可以并行执行多个任务。

4. 学习使用 UART：接收 DT7 遥控器和 DR16 接收机发来的控制量。

5. 完成底盘控制：进行四舵轮底盘正运动学解算，结合解算结果和 pid 控制器，让底盘根据遥控器的输入进行运动。

![](./assets/image.png)

## 🔗 参考资料

- [RoboMaster 开发板 C 型](https://www.robomaster.com/zh-CN/products/components/general/development-board-type-c#downloads)

- [RoboMaster 开发板 C 型嵌入式软件教程文档](https://github.com/RoboMaster/Development-Board-C-Examples/blob/master/RoboMaster%E5%BC%80%E5%8F%91%E6%9D%BFC%E5%9E%8B%E5%B5%8C%E5%85%A5%E5%BC%8F%E8%BD%AF%E4%BB%B6%E6%95%99%E7%A8%8B%E6%96%87%E6%A1%A3.pdf)

- [通俗易懂的 PID 控制算法讲解](https://www.bilibili.com/video/BV1et4y1i7Gm)

- [RoboMaster/Development-Board-C-Examples](https://github.com/RoboMaster/Development-Board-C-Examples)

- [DT7&DR16 2.4GHz 遥控接收系统](https://www.robomaster.com/zh-CN/products/components/detail/122)

- [GM6020 云台电机](https://www.robomaster.com/zh-CN/products/components/general/GM6020)

- [M3508 减速电机套装](https://www.robomaster.com/zh-CN/products/components/general/M3508)

- [DM-J4310-2EC V1.1减速电机说明书V1.0](https://gitee.com/kit-miao/damiao/raw/master/%E5%85%B3%E8%8A%82%E7%94%B5%E6%9C%BA/DM-J4310-2EC/%E8%AF%B4%E6%98%8E%E4%B9%A6/DM-J4310-2EC%20V1.1%E5%87%8F%E9%80%9F%E7%94%B5%E6%9C%BA%E8%AF%B4%E6%98%8E%E4%B9%A6V1.0.pdf)

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
