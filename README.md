# Calc

Calc 是一个基于 **Qt 6 / C++** 开发的跨平台桌面应用程序，集成以下功能：

- 🧮 **计算器（Calculator）**
- ⏱ **计时器（Timer）**
- 📄 **文件编辑器（Filer）** — 新增功能

项目旨在展示 Qt Widgets 桌面应用开发，学习事件驱动机制和多模块功能在同一程序中的实现。  

[项目地址](https://github.com/Chtx666/Calc)

---

## 功能概览

### 🧮 Calculator（计算器）

- 支持四则运算：加、减、乘、除  
- 支持小数与括号运算  
- 实时显示计算结果  
- 异常输入处理（如连续符号、非法字符）

### ⏱ Timer（计时器）

- 提供 **开始 / 暂停 / 重置** 功能  
- 基于 Qt 定时器实现  
- 适合学习计时或专注练习

### 📄 Filer（文件编辑器） — **新增功能**

- 打开任意文本文件  
- 编辑文件内容  
- 保存修改后的文件  
- 用户可自定义路径选择  

> Filer 与 Calculator、Timer 在程序中平级共存，可通过菜单或按钮切换模块使用。

---

## 技术栈

- **语言**：C++  
- **GUI 框架**：Qt 6 (Qt Widgets)  
- **构建系统**：qmake  
- **开发环境**：Qt Creator  
- **兼容平台**：Windows / Linux（如 Fedora / KDE）

---

## 项目结构

Calc 仓库当前实际文件结构如下：


Calc/
├── .gitignore
├── Calc.pro
├── LICENSE 
├── README.md 
├── main.cpp 
├── mainwindow.h 
├── mainwindow.cpp
└── mainwindow.ui 


> 注意：虽然项目没有为各模块建立单独文件夹，但内部逻辑上区分了 **Calculator、Timer 和 Filer** 模块。

---

## 安装与使用

### 克隆项目

```bash
git clone https://github.com/Chtx666/Calc.git
