## 面向对象设计原则(8 个)

1. 依赖倒置原则(DIP);
2. 开放封闭原则(OCP);
3. 单一职责原则(SRP);
4. Liskov 替换原则(LSP):
   - 子类必须能够替换它们的基类(IS-A);
   - 继承表达类型抽象.
5. 接口隔离原则(ISP):
   - 不应该强迫客户程序依赖他们不用的方法;
   - 接口应该尽可能小.
6. 优先使用对象组合, 而不是类继承:
   - 类继承通常为"白箱复用", 对象组合通常为"黑箱复用";
   - 继承在某种程度上
7. 封装变化点
   - 使用封装来创建对象之间的分界层
8. 针对接口编程, 而不是针对实现编程:
   - 与依赖倒置原则相辅相成.
   - 实现"高内聚, 松耦合".

## 将设计原则提升为设计经验

1. 设计习语
2. 设计模式
3. 架构模式

## 设计模式的分类（GOF-23）

### 从目的来看

- 创建型（creational）模式：

- 结构型（structural）模式：

- 行为型（behavioral）模式：

### 从范围来看

- 类模式处理类与子类的静态关系

- 对象模式处理对象间的动态关系

## 设计模式(23 个)： 从封装变化角度分类模式

### 组件协作类

通过晚期绑定， 实现框架与应用程序之间的松耦合

1. Template Method

2. Observer/Event

3. Strategy

## 单一职责

1. Decorater

2. Bridge

## 对象创建

1. Factory Method

2. Abstract Factory

3. Prototype

4. Builder

## 对象性能

1. Singleton

2. Flyweight

## 接口隔离

1. Facade

2. Proxy

3. Mediator

4. Adapter

## 状态变化

1. Memento

2. State

## 数据结构

1. Composite

2. Iterator

3. Chain of Responsibility

## 行为变化

1. Command

2. Visitor

## 领域问题

1. Interpreter
