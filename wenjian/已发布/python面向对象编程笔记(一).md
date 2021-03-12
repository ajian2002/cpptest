# 声明

学习资料来源于 github 热门项目

[Python-Core-50-Courses](https://github.com/jackfrued/Python-Core-50-Courses)

以及

[Python-100-Days](https://github.com/jackfrued/Python-100-Days)

本文仅限于初学 python 的面向对象,笔者对于面向对象思想并不十分了解,如有错误请指出.以及本文会在笔者彻底掌握后进行修正.

# 定义类

`class Student:`
或
`class Student(object):`

# 类内部的函数

```python
    def __init__(self,name=0,age=0):
        # 初始化方法
        self.name=name
        self.age=age
        self.score=None
    """
    创建类实例化时自动执行的函数,可以为类附加属性
    参数必须包含self 其余参数如果设置默认值可以不填

    也有种方法

        def __init__(self, **kw):
            if 'hour' in kw and 'minute' in kw and 'second' in kw:
                self._hour = kw['hour']
                self._minute = kw['minute']
                self._second = kw['second']
            else:
                tm = time.localtime(time.time())
                self._hour = tm.tm_hour
                self._minute = tm.tm_min
                self._second = tm.tm_sec

    """

    def fun2(self):
    # 其他函数
        print('abc')
    def study(self,doing):
        print(doing)
```

# 创建类的实例(对象)

```python
def main():
    Student1=Student()  ''' 创建类的实例化'''
```

# 使用对象

> 通过“类.方法”调用方法，第一个参数是接收消息的对象 self，第二个参数为类中函数的参数

`Student.study(Student1, '学习') `

> 通过“对象.方法”调用方法，点前面的对象就是接收消息的对象，只需要传入函数参数

`Student1.study('学习') `

# 打印对象

类中放置 `__repr__`函数 或 `__str__`函数 可以控制打印内容

Python 定义了`__str__()`和`__repr__()`两种方法`__str__()`用于显示给用户，而`__repr__()`用于显示给开发人员。

```python
def __repr__(self):
        return f'{self.name}: {self.age}'

def main():
    st=Student()
    print(st)
    # 0 0                                  定义之后
    # <main.Person object at 0x10c941890>  未定义直接打印

```

# 可见性

python 中 可以用

`__name表示一个私有(private)属性`，

`_name表示一个受保护(protected)属性`

若

类 class Student 中定义一个 `self.__name`变量

类外部无法访问`st.__name`

需要`st._Student__name`访问

而在类内部 成员函数可以直接`self.__name` 访问

> 但是 python 并没有从语法上严格保证私有属性的私密性，它只是给私有的属性和方法换了一个名字来阻挠对它们的访问，事实上如果你知道更换名字的规则仍然可以访问到它们，我们可以对上面的代码稍作修改就可以访问到私有的

# 属性装饰器

## @property 提供外部访问方法

```python

class Student:
# 属性访问器(getter方法) - 获取__name属性
    @property
    def name(self):
        return self.__name
    #其余内容省略

def main():
    st=Student("姓名")
    print(st.name)  #姓名
    st.name=''
    print(st.name)  # 空串
```

或

```py

    #装饰器 @property
    def tag(self):
        return self.name + str(self.age)
print(user.tag())
# print(user.tag)
```

> tag 与其说是一个`函数`其实更像是`user对象的一个属性`，用`user.tag()`的方法获取显得不那么自然，而使用`@property装饰器`我们就可以用 user 属性的方式来得到 tag：
>
> print(user.tag)

## @\*.setter 预处理

两个同名函数打上`@property装饰器`和后`@*.setter装饰器`，当把函数作为变量赋值时会触发`@*.setter`对应的函数，当把函数作为变量读取时会触发`@property`对应的函数，因此我们可以将其用于数据的预处理。

```python
class User():
    def __init__(self, name, age):
        self.name = name
        self._age = age

    @property
    def age(self):
        return self._age
    @age.setter
    def age(self,n):
        self._age = n + 5

user = User('xiao',0)
user.age = 5  #加密处理  5+5



```

# 动态属性

我们可以动态为对象添加属性

## `__slots__` 限制属性

如果不希望在使用对象时动态的为对象添加属性，可以使用 Python 的`__slots__`魔法。对于 Student 类来说，可以在类中指定`__slots__ = ('name', 'age')`，这样 Student 类的对象只能有 name 和 age 属性，如果想动态添加其他属性将会引发异常

```python
class Student:
    __slots__ = ('name', 'age')

    def __init__(self, name, age):
        self.name = name
        self.age = age
def main():
    # 省略
    st.sex='girl' # 出错
```

# 静态方法和类方法

## @staticmethod 静态方法

之前我们在类中定义的方法都是`对象方法`，换句话说这些方法都是`对象可以接收的消息`。除了对象方法之外，类中还可以有`静态方法`和`类方法`，这两类方法是`发给类的消息`，二者并没有实质性的区别。

> 第一个参数

> 对象方法的是 **普通对象**

> 类方法的是**类对象**

> 静态方法的是**没有接受消息的对象** #可以不和类绑定写成普通函数

```python
@staticmethod   # 静态方法
    def is_valid(a, b, c):
        """判断三条边长能否构成三角形(静态方法)"""
        return a + b > c and b + c > a and a + c > b
```

# 继承和多态

面向对象的编程语言支持在已有类的基础上创建新类，从而减少重复代码的编写。

> 提供继承信息的类叫做`父类（超类、基类）`

> 得到继承信息的类叫做`子类（派生类、衍生类）`

```python
class Person:
    """人类"""
class Student(Person):
    """学生类"""
class Teacher(Person):
    """老师类"""
```

继承的语法是在定义类的时候，在`类名后的圆括号中指定当前类的父类`。

如果定义一个类的时候没有指定它的父类是谁，那么`默认的父类是object类`。object 类是 Python 中的顶级类，这也就意味着`所有的类都是它的子类`，要么直接继承它，要么间接继承它。Python 语言允许多重继承，也就是说一个类可以有一个或多个父类.

## @abstractmethod 包装器

子类必须重写(不能创建类对象,须继承重写)

```python
class Pet(object, metaclass=ABCMeta):
    def __init__(self,name):
        self.name=name
    # @abstractmethod   #
    def voice(self):
        # pass
```
