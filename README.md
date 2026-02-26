# Calc

**Calc** 是一个基于 **Qt 6 / C++** 开发的跨平台桌面应用程序，集成了 **计算器（Calculator）** 与 **计时器（Timer）** 两个功能模块。  
该项目旨在作为 Qt Widgets 应用的学习与实践示例，侧重于界面设计、事件驱动模型以及多功能模块在同一程序中的组织方式。

项目仓库：  
https://github.com/Chtx666/Calc

---

## ✨ 功能概述

### Calculator（计算器）
- 支持基本四则运算（加 / 减 / 乘 / 除）
- 支持小数输入与计算
- 结果实时显示
- 逻辑实现清晰，便于理解与扩展

### Timer（计时器）
- 与计算器功能并存于同一应用中
- 支持 **开始 / 暂停 / 重置**
- 基于 Qt 定时器机制实现
- 可用于简单计时、学习或专注辅助场景

> 两个功能模块在逻辑与交互上相互独立，便于后续继续添加新功能模块。

---

## 🧩 技术栈

- **编程语言**：C++
- **GUI 框架**：Qt 6（Qt Widgets）
- **构建系统**：qmake
- **开发环境**：Qt Creator
- **测试平台**：
  - Windows
  - Linux（Fedora / KDE Plasma）

---

## 📁 项目结构

```text
Calc/
├── Calc.pro              # Qt 项目配置文件
├── main.cpp              # 程序入口
├── mainwindow.h          # 主窗口类声明
├── mainwindow.cpp        # 主窗口逻辑实现
├── mainwindow.ui         # UI 布局文件（Qt Designer）
├── LICENSE               # 开源许可证
└── README.md             # 项目说明文档
