# 任务五：云台控制 - 驱动 CAN 总线电机/姿态解算/PID 控制器

## 📃 任务描述

根据 IMU 的数据驱动云台电机，让一台步兵机器人死死盯住一个方向！

![](./assets/1.gif)

## 参考步骤

1. 获取 IMU 数据、姿态解算：读取 C 板上板载的 BMI088 IMU 的陀螺仪和加速度计数据，自行选择合适的姿态解算算法获取云台姿态的三个欧拉角

2. 完成云台控制：以解算出的姿态数据作为参考，利用 PID 控制器控制云台上的 yaw 轴电机和 pitch 轴电机，不管底盘如何运动或者受到什么扰动，都让云台稳稳地朝向一个固定的方向

## 🔗 参考资料

### 教程

- [通俗易懂的 PID 控制算法讲解](https://www.bilibili.com/video/BV1et4y1i7Gm)

- [【keysking的STM32教程】第8集 STM32的串口通信](https://www.bilibili.com/video/BV1Na4y1T7VQ/?share_source=copy_web&vd_source=705edeb1573287133e920650d6885caf)

- [CAN总线入门教程-全面细致 面包板教学 多机通信](https://www.bilibili.com/video/BV1vu4m1F7Gt/?share_source=copy_web&vd_source=705edeb1573287133e920650d6885caf)

- [单片机也能跑多线程？5分钟带你入门FreeRTOS](https://www.bilibili.com/video/BV1mF4m1A7sp/?share_source=copy_web&vd_source=705edeb1573287133e920650d6885caf)

- [【STM32】使用CubeMX快速创建FreeRTOS的基础工程](https://blog.csdn.net/youuuuvvu/article/details/132559730)

### 相关文档资料

- [RoboMaster 开发板 C 型](https://www.robomaster.com/zh-CN/products/components/general/development-board-type-c#downloads)

- [RoboMaster 开发板 C 型嵌入式软件教程文档](https://github.com/RoboMaster/Development-Board-C-Examples/blob/master/RoboMaster%E5%BC%80%E5%8F%91%E6%9D%BFC%E5%9E%8B%E5%B5%8C%E5%85%A5%E5%BC%8F%E8%BD%AF%E4%BB%B6%E6%95%99%E7%A8%8B%E6%96%87%E6%A1%A3.pdf)

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
