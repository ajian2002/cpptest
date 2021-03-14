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
```
numbers1 = [35, 12, 8, 99, 60, 52]
numbers2 = list(map(lambda x: x ** 2, filter(lambda x: x % 2 == 0, numbers1)))
print(numbers2)    # [144, 64, 3600, 2704]
```

>filter和map函数就是高阶函数，前者可以实现对序列中元素的过滤，后者可以实现对序列中元素的映射，


## 匿名函数lambda

匿名函数只能有一行代码，代码中的表达式产生的运算结果就是这个匿名函数的返回值


```
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



# 装饰器