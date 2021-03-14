[Python学习笔记 生成式和生成器
](https://blog.csdn.net/dark_cy/article/details/99577679)

## raise 引发自定义异常
raise myerror(argv)
```py
class MyError(RuntimeError):
    def __init__(self, argv):
        self.argv=argv

try:
    raise MyError("hello")
except MyError as e:
    print(e.argv)
```

## 断言与自定义异常
```py
s=input()
try:
    assert len(s)<=5
    print(s)
except AssertionError:
    print("assert error")
```
## 可变参数与关键字参数
[python的可变参数和关键字参数(*args **kw)](https://www.jianshu.com/p/98f7e34845b5)

### 可变参数 *args (tuple)
```py
def calc(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum

nums = [1, 2, 3]
calc(*nums) #14  
# *nums表示把nums这个list/tuple的所有元素作为可变参数传进去。
```
### 关键字参数 **kw (dict)
```py
def person(name, age, **kw):
    print('name:', name, 'age:', age, 'other:', kw)
person('Adam', 45, gender='M', job='Engineer')
# name: Adam age: 45 other: {'gender': 'M', 'job': 'Engineer'}
```
```py
>>> extra = {'city': 'Beijing', 'job': 'Engineer'}
>>> person('Jack', 24, **extra)
name: Jack age: 24 other: {'city': 'Beijing', 'job': 'Engineer'}
```
kw获得的dict是extra的一份拷贝，对kw的改动不会影响到函数外的extra
```py
if 'city' in kw:
        # 有city参数
        pass
    if 'job' in kw:
        # 有job参数
        pass
```
### 命名关键字参数

如果要限制关键字参数的名字，就可以用命名关键字参数，例如，只接收city和job作为关键字参数。这种方式定义的函数如下：

```py
def person(name, age, *, city, job):
    print(name, age, city, job)
person('Jack', 24, city='Beijing', job='Engineer')
# Jack 24 Beijing Engineer
```


## filter与map函数(过滤,映射)
```py
numbers1 = [35, 12, 8, 99, 60, 52]
numbers2 = list(map(lambda x: x ** 2, filter(lambda x: x % 2 == 0, numbers1)))
print(numbers2)    # [144, 64, 3600, 2704]
```

>filter和map函数就是高阶函数，前者可以实现对序列中元素的过滤，后者可以实现对序列中元素的映射，


## 匿名函数lambda

匿名函数只能有一行代码，代码中的表达式产生的运算结果就是这个匿名函数的返回值


```py
import operator, functools

# 一行代码定义求阶乘的函数
fac = lambda num: functools.reduce(operator.mul, range(1, num + 1), 1)
# 一行代码定义判断素数的函数
is_prime = lambda x: x > 1 and all(map(lambda f: x % f, range(2, int(x ** 0.5) + 1)))

# 调用Lambda函数
print(fac(10))        # 3628800
print(is_prime(9))    # False
```
>reduce函数是Python标准库functools模块中的函数，它可以实现对数据的归约操作

> all函数 如果所有都是True返回True，否则返回False



# 装饰器(简单)

## 函数
```PY
import time
# 定义装饰器函数，它的参数是被装饰的函数或类
def record_time(func):
    # 定义一个带装饰功能（记录被装饰函数的执行时间）的函数
    # 因为不知道被装饰的函数有怎样的参数所以使用*args和**kwargs接收所有参数
    def wrapper(*args, **kwargs):
        start = time.time()
        # 执行被装饰的函数并获取返回值
        result = func(*args, **kwargs)
        end = time.time()
        print(f'{func.__name__}执行时间: {end - start:.3f}秒')
        # 返回被装饰函数的返回值（装饰器通常不会改变被装饰函数的执行结果）
        return result
    
    # 返回带装饰功能的wrapper函数
    return wrapper

@record_time  #语法糖
def download(filename):
    print(f'开始下载{filename}.')
    time.sleep(random.randint(2, 6))
    print(f'{filename}下载完成.')
@record_time 
def upload(filename):
    print(f'开始上传{filename}.')
    time.sleep(random.randint(4, 8))
    print(f'{filename}上传完成.')

download('MySQL从删库到跑路.avi')
upload('Python从入门到住院.pdf')
```
>事实上，被装饰后的download和upload函数是我们在装饰器record_time中返回的wrapper函数，调用它们其实就是在调用wrapper函数，所以拥有了记录函数执行时间的功能。

>语法糖相当于
`download = record_time(download)`


### 加一个装饰开关

`被装饰fun.\_\_wrapped\_\_(*args)`
```py
'''省略'''
    @wraps(func)
    def wrapper(*args, **kwargs):
'''省略'''
# 使用装饰器
download('MySQL从删库到跑路.avi')
upload('Python从入门到住院.pdf')
# 取消装饰器
download.__wrapped__('MySQL必知必会.pdf')
upload = upload.__wrapped__
upload('Python从新手到大师.pdf')
```


## 类
如果一个类中有名为__call__的魔术方法，那么这个类的对象就可以像函数一样调用，这就意味着这个对象可以像装饰器一样工作
```py
class RecordTime:
    
    def __call__(self, func):

        @wraps(func)
        def wrapper(*args, **kwargs):
            start = time.time()
            result = func(*args, **kwargs)
            end = time.time()
            print(f'{func.__name__}执行时间: {end - start:.3f}秒')
            return result

        return wrapper

# 使用装饰器语法糖添加装饰器
@RecordTime()
def download(filename):
    print(f'开始下载{filename}.')
    time.sleep(random.randint(2, 6))
    print(f'{filename}下载完成.')


# 直接创建对象并调用对象传入被装饰的函数
# 调用构造器创建对象的语法
upload = RecordTime()(upload)

download('MySQL从删库到跑路.avi')
```