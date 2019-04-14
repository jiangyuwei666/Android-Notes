# 杀安德杀pdd
算是复习的大纲
## 1.杂谈
* 针对招聘信息进行查漏补缺。
* 针对招聘信息，修改不同的简历以展现匹配度。
* 舔（贵公司的资深用户）

面试的：（一面基础、二面项目、三面设计）
* 学生：学历和成绩、计算机课程、在校项目/实习经验
* 行为面试：自我介绍、口头、沟通能力

技术栈：
* web请求流程：浏览器》负载均衡》web框架》业务逻辑》数据库缓存
* python
* 算法数据结构
* 编程范式（面向对象、设计模式、函数是编程）
* 操作系统
* 网络编程
* 数据库
* web框架
* 系统设计

简历和面试：
* 简历：
    * 突出个人优势
    * 突出职业技能
    * 关键项目经验
    * 加分项（项目、技术栈比较匹配、开源项目）
* 面试：
    * 自我介绍（个人信息、求职意向）
    * 行为面试
        * 说说你曾经。。。说说你这个项目。。。技术难点。。。

            情景、任务、行动、结果
    * 反问
        * 表现出兴趣：工作内容、技术栈、团队。。。。
        * 
## 2.python语言
* 动态强类型

    编译器还是运行期确定类型、隐式类型转换（1 + '1'）
* 为什么用？

    轮子多、生产力高

    性能问题、代码维护  2/3不兼容
* 鸭子类型（走起来像鸭子，叫起来叫鸭子）

    对象的行为、而不是类型
* monkey patch 猴子补丁

    * 运行时替换（gevent）
* 自省

    运行时判断一个对象的类型
* 生成式
* python之禅
### python2/3差异
* print成为函数 python2中是关键字（sep = '|'）
* 编码
* 除法 float //

python3的改进
* 类型注解
* super()
* 高级解包操作
    ```
    In [1]: a, b, *c = range(10)

    In [2]: print(a,b,c)
    0 1 [2, 3, 4, 5, 6, 7, 8, 9]
    ```
* 限定关键字参数
* 重新抛出
* 返回迭代器，不再是list，比如`range()`函数，节省类型
* `__pycache__`
* 异步、枚举等多种库
* 兼容2/3的工具

    * `__future__`
    * six模块
### python函数
* 传参--共享传参

    函数形参获得实参中各个引用的拷贝副本(copy)

    传递方式是一样的，但是在可变类型的参数会影响这个值。不可变类型不会
* 可变和不可变

    ```python
    In [3]: def clear_list(l):
    ...:     l = []
    ...: 

    In [4]: ll = [1,2,3]

    In [5]: clear_list(ll)

    In [6]: ll
    Out[6]: [1, 2, 3]
    ```
    可变对象作为参数
    ```python
    In [13]: def flist(l):
        ...:     l.append(0)
        ...:     print(l)
        ...: 

    In [14]: ll = []

    In [15]: flist(ll)
    [0]

    In [16]: flist(ll)
    [0, 0]

    In [17]: l
    Out[17]: [0, 0]
    ```
    这里这个形参`l`其实也是指向`ll`所指向的列表，所以操作的时候也是操作的`ll`
    
    但是传入的参数是不可变对象，比如说是str类型的。
    ```python
    In [22]: def fstr(s):
        ...:     s += 'a'
        ...:     print(s)
        ...: 

    In [23]: ss = 'xxx'

    In [24]: fstr(ss)
    xxxa

    In [25]: fstr(ss)
    xxxa

    In [26]: fstr(ss)
    xxxa

    In [27]: ss
    Out[27]: 'xxx'
    ```
    其实形参`s`也是指向实参`ss`所指向的那一个字符串，但是由于操作是在字符串后面加一个东西，而事实上是不允许这样做的，所以这个时候会创建一个字符串这里是`'xxxa'`，并且让`s`指向这个字符串。所以`ss`还是指向的`'xxx'`而`s`指向的是`'xxxa'`

* `*args`和`**kwargs`
### 异常机制
    ```
    try:
    except xxx as e:
    else:
    finally:
    ```
### 性能分析与优化、GIL

GIL：限制多核执行。CPU密集难以利用多核优势。IO密集程序影响不大。

profile/cprofile:
### 服务端性能优化措施
* 数据结构和算法的优化
* 数据库的优化：索引、减少慢查询、批量操作减少IO、NoSQL
* 网络IO:批量操作
* 缓存：redis
* 异步：asyncio,celery
* 并发：gevent/线程
### 生成器与协程
### 单元测试
* nose/pytest
* mock用来替换网络请求
* coverage统计测试覆盖率
### 基础练习题
* 深浅拷贝
* 初始化二维数组

## 3.数据结构算法
### 数据结构
常用的内置算法和数据结构？
用过collections模块吗？
* namedtuple
* Counter
* OrderedDict() dict的Key无序， 这个key有序
* defalutdict() 带有默认值的字典，访问不存在的不会报错

**哈希表的底层原理何实现？怎么解决hash冲突？怎么扩容？**

list和tuple区别？引用不可变

LRUCache替换最近使用最少的
双端队列，将最近使用的放到最前面

### 算法
## 4.面向对象基础以及python类常考问题
* 面向对象？封装继承多态
* classmethod/staticmethod

    classmethod第一个参数是cls，可以使用类变量。staticmethod和普通函数一样，只不过放在了类里面
* 元类--创建类的类
    * 控制类的生成，修改类的属性
    * 使用type定义元类
    * ORM框架
### 装饰器
接收一个函数作为参数，然后返回一个新的函数
### 设计模式
设计模式一般分为三种类型
#### 创建型
* **工厂模式**(Factory):解决对象创建问题
* 构造模式(Builder):控制复杂对象的创建(每一步创建一个组件)
* 原型模式(Prototype):通过原型的克隆来创建新的实例
* **单例模式**(Singleton):一个类只能创建同一个对象
    ```python
    class Singleton:
    def __new__(cls, *args, **kwargs):
        if not hasattr(cls, '_instance'):
            _instance = super().__new__(cls, *args, **kwargs)
            cls._instance = _instance
        return cls._instance
    class MyClass:
        pass
    class SubSingleton(Singleton):
        pass
    c1 = MyClass()
    c2 = MyClass()

    s1 = SubSingleton()
    s2 = SubSingleton()
    s3 = Singleton()
    s4 = Singleton()
    print(c1 is c2)
    print(s1 is s2)
    print(s1 is s3)
    print(s3 is s4)
    ```
    ```
    False
    True
    False
    True
    ```
* 对象池模式(Pool):预先分配同一类型的一组实例
#### 结构型
* **装饰器模式**(Decorator):无需使用子类就能实现对对象功能的扩展
* **代理模式**(Proxy):把一个对象的操作代理到另外一个对象
* **适配器模式**(Adapter):通过一个间接层适配统一接口
* 外观模式(Facade):简化复杂对象的访问问题
* 享元模式(Flyweight):通过对象复用池改善资源利用，比如连接池
* **Model-View-Controller**(MVC):解耦 显示逻辑和业务逻辑
#### 行为型
* **迭代器模式**(Iterator):通过统一的接口迭代对象
    * `__iter__()`和`__next__()`
* **观察者模式**(Observer):对象发生改变时，观察者指向相应的动作
    * 发布订阅是一种最常用的实现方式
    * 通过回调 
* **策略模式**(Strategy):针对不同规模输入使用不同的策略
### 闭包
外部使用结束了，如果内部函数还在执行，那么外部的变量就还可以用。
## 5.操作系统
### Linux常考命令
* 文件/目录操作命令
* 文件查看
* 进程操作的命令
* 内存操作命令
* 网络操作命令
* 用户/组操作命令

《鸟哥的linux私房菜》
### 进程和线程
* 线程和进程的区别和关系
* 线程安全(GIL锁)
    * 线程同步
        * 互斥量(锁)
        * 信号量
        * 事件
* 进程间的通信方式
    * pipe  管道
    * 信号(signal)
    * 消息队列(Message)
    * 信号量
    * 套接字(socket)
* python中实现多线程
* python中使用多进程
### 内存管理机制
* 分页机制
* 分段机制
* 虚拟内存
    * 暂时不用的东西放在硬盘上，，要用的时候再拿出来
    
    导致内存抖动
    * 频繁调度页行为
* python垃圾回收机制原理

    * 引用计数(主要)
        
        比如：
        * 增加引用计数：创建对象、让一个引用指向这个对象、**函数调用**
        * 减少引用计数：del减少对象引用计数
        
        无法结局循环引用，所有需要使用下面的回收机制
    * 标记清除和分代回收(辅助)
        
        两个对象相互引用，引用计数无法置为0

        6-3
## 6.网络
### 网络协议
* 输入一个url过后经历了哪些过程
    * 涉及到了哪些过程
    * 包含哪些网络协议
    * 每个协议都干了些什么

    DNS查询(缓存))--TCP握手(建立连接)--HTTP请求--反向代理Nginx--uwsgi/gunicorn--web app响应--TCP挥手(断开连接)
* TCP/UDP区别
### HTTP协议
HTTP是TCP应用层协议(HTTP和TCP关系)
* HTTP请求的组成
    * 状态行
    * 请求头
    * 消息主体
* HTTP响应的组成
    * 响应码
    * 响应头
    * 响应主体
* HTTP状态码
    * 1xx。服务器收到请求，需要请求者继续执行操作
    * 2xx。成功
    * 3xx。重定向（301永久，302临时重定向）
    * 4xx。客户错误
    * 5xx。服务器错误
* HTTP 请求方法
    * get post区别
    * 幂等性 安全性
* HTTP长连接
* cookie和session区别
### 网络编程
* TCP/UDP socket编程原理(视频7-3)
* 使用socket发送HTTP请求
### IO多路复用
* 五种IO模型
    * Blocking IO  阻塞IO
    * Nonblocking IO  非阻塞IO
    * IO multiplexing  IO多路复用
    * Singal Driven IO  信号IO (不常用)
    * Asynchronous IO  异步IO (不常用)
* 如何提升并发能力
    * 多线程
    * 多进程
    * IO多路复用
* 什么是IO多路复用？
* 阻塞式IO
* 