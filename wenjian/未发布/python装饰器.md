[Python 学习笔记 生成式和生成器
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

[python 的可变参数和关键字参数(\*args \*\*kw)](https://www.jianshu.com/p/98f7e34845b5)

### 可变参数 \*args (tuple)

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

### 关键字参数 \*\*kw (dict)

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

kw 获得的 dict 是 extra 的一份拷贝，对 kw 的改动不会影响到函数外的 extra

```py
if 'city' in kw:
        # 有city参数
        pass
    if 'job' in kw:
        # 有job参数
        pass
```

### 命名关键字参数

如果要限制关键字参数的名字，就可以用命名关键字参数，例如，只接收 city 和 job 作为关键字参数。这种方式定义的函数如下：

```py
def person(name, age, *, city, job):
    print(name, age, city, job)
person('Jack', 24, city='Beijing', job='Engineer')
# Jack 24 Beijing Engineer
```

## filter 与 map 函数(过滤,映射)

```py
numbers1 = [35, 12, 8, 99, 60, 52]
numbers2 = list(map(lambda x: x ** 2, filter(lambda x: x % 2 == 0, numbers1)))
print(numbers2)    # [144, 64, 3600, 2704]
```

> filter 和 map 函数就是高阶函数，前者可以实现对序列中元素的过滤，后者可以实现对序列中元素的映射，

## 匿名函数 lambda

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

> reduce 函数是 Python 标准库 functools 模块中的函数，它可以实现对数据的归约操作

> all 函数 如果所有都是 True 返回 True，否则返回 False

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

> 事实上，被装饰后的 download 和 upload 函数是我们在装饰器 record_time 中返回的 wrapper 函数，调用它们其实就是在调用 wrapper 函数，所以拥有了记录函数执行时间的功能。

> 语法糖相当于
> `download = record_time(download)`

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

如果一个类中有名为**call**的魔术方法，那么这个类的对象就可以像函数一样调用，这就意味着这个对象可以像装饰器一样工作

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

# base64

```py
import base64
contents=b"asdsafafsdg213125w4tww46568AS"
s=base64.b64encode(contents)#编码必须参数字节包
print(s)
# b'YXNkc2FmYWZzZGcyMTMxMjV3NHR3dzQ2NTY4QVM='
print(base64.b64decode(s)) # 解码随意
# b'asdsafafsdg213125w4tww46568AS'
```

# collections - 容器数据类型模块

`collections`模块提供了诸多非常好用的数据结构，主要包括：

-   `namedtuple`：命令元组，它是一个类工厂，接受类型的名称和属性列表来创建一个类。
-   `deque`：双端队列，是列表的替代实现。Python 中的列表底层是基于数组来实现的，而`deque`底层是双向链表，因此当你需要在头尾添加和删除元素是，`deque`会表现出更好的性能，渐近时间复杂度为$O(1)$。
-   `Counter`：`dict`的子类，键是元素，值是元素的计数，它的`most_common()`方法可以帮助我们获取出现频率最高的元素。`Counter`和`dict`的继承关系我认为是值得商榷的，按照 CARP 原则，`Counter`跟`dict`的关系应该设计为关联关系更为合理。
-   `OrderedDict`：`dict`的子类，它记录了键值对插入的顺序，看起来既有字典的行为，也有链表的行为。
-   `defaultdict`：类似于字典类型，但是可以通过默认的工厂函数来获得键对应的默认值，相比字典中的`setdefault()`方法，这种做法更加高效。

# hashlib - 哈希函数模块

哈希函数又称哈希算法或散列函数，是一种为已有的数据创建“数字指纹”（哈希摘要）的方法。哈希函数把数据压缩成摘要，对于相同的输入，哈希函数可以生成相同的摘要（数字指纹），需要注意的是这个过程并不可逆（不能通过摘要计算出输入的内容）。一个优质的哈希函数能够为不同的输入生成不同的摘要，出现哈希冲突（不同的输入产生相同的摘要）的概率极低，[MD5](https://zh.wikipedia.org/wiki/MD5)、[SHA 家族](<[https://zh.wikipedia.org/wiki/SHA%E5%AE%B6%E6%97%8F](https://zh.wikipedia.org/wiki/SHA家族)>)就是这类好的哈希函数。

> **说明**：在 2011 年的时候，RFC 6151 中已经禁止将 MD5 用作密钥散列消息认证码，这个问题不在我们讨论的范围内。

Python 标准库的`hashlib`模块提供了对哈希函数的封装，通过使用`md5`、`sha1`、`sha256`等类，我们可以轻松的生成“数字指纹”。举一个简单的例子，用户注册时我们希望在数据库中保存用户的密码，很显然我们不能将用户密码直接保存在数据库中，这样可能会导致用户隐私的泄露，所以在数据库中保存用户密码时，通常都会将密码的“指纹”保存起来，用户登录时通过哈希函数计算密码的“指纹”再进行匹配来判断用户登录是否成功。

```Python
import hashlib

# 计算字符串"123456"的MD5摘要
print(hashlib.md5('123456'.encode()).hexdigest())

# 计算文件"Python-3.7.1.tar.xz"的MD5摘要
hasher = hashlib.md5()
with open('Python-3.7.1.tar.xz', 'rb') as file:
    data = file.read(512)
    while data:
        hasher.update(data)
        data = file.read(512)
print(hasher.hexdigest())
```

# os.path - 路径操作相关模块

`os.path`模块封装了操作路径的工具函数，如果程序中需要对文件路径做拼接、拆分、获取以及获取文件的存在性和其他属性，这个模块将会非常有帮助，下面为大家罗列一些常用的函数。

-   `dirname(path)`：返回路径`path`的目录名称。
-   `exists(path)`：如果`path`指向一个已存在的路径或已打开的文件描述符，返回 `True`。
-   `getatime(path)` / `getmtime(path)` / `getctime(path)`：返回`path`的最后访问时间/最后修改时间/创建时间。
-   `getsize(path)`：返回`path`的大小，以字节为单位。如果该文件不存在或不可访问，则抛出`OSError`异常。
-   `isfile(path)`：如果`path`是普通文件，则返回 `True`。
-   `isdir(path)`：如果`path`是目录（文件夹），则返回`True`。
-   `join(path, *paths)`：合理地拼接一个或多个路径部分。返回值是`path`和`paths`所有值的连接，每个非空部分后面都紧跟一个目录分隔符 (`os.sep`)，除了最后一部分。这意味着如果最后一部分为空，则结果将以分隔符结尾。如果参数中某个部分是绝对路径，则绝对路径前的路径都将被丢弃，并从绝对路径部分开始连接。
-   `splitext(path)`：将路径`path`拆分为一对，即`(root, ext)`，使得`root + ext == path`，其中`ext`为空或以英文句点开头，且最多包含一个句点。

# json

`json`模块有四个比较重要的函数，分别是：

-   `dump` - 将 Python 对象按照 JSON 格式序列化到文件中
-   `dumps` - 将 Python 对象处理成 JSON 格式的字符串
-   `load` - 将文件中的 JSON 数据反序列化成对象
-   `loads` - 将字符串的内容反序列化成 Python 对象

# 正则

关于正则表达式的相关知识，大家可以阅读一篇非常有名的博文叫[《正则表达式 30 分钟入门教程》](https://deerchao.net/tutorials/regex/regex.htm)，读完这篇文章后你就可以看懂下面的表格，这是我们对正则表达式中的一些基本符号进行的扼要总结。

| 符号                     | 解释                              | 示例                | 说明                                                                                  |
| ------------------------ | --------------------------------- | ------------------- | ------------------------------------------------------------------------------------- |
| .                        | 匹配任意字符                      | b.t                 | 可以匹配 bat / but / b#t / b1t 等                                                     |
| \\w                      | 匹配字母/数字/下划线              | b\\wt               | 可以匹配 bat / b1t / b_t 等<br>但不能匹配 b#t                                         |
| \\s                      | 匹配空白字符（包括\r、\n、\t 等） | love\\syou          | 可以匹配 love you                                                                     |
| \\d                      | 匹配数字                          | \\d\\d              | 可以匹配 01 / 23 / 99 等                                                              |
| \\b                      | 匹配单词的边界                    | \\bThe\\b           |                                                                                       |
| ^                        | 匹配字符串的开始                  | ^The                | 可以匹配 The 开头的字符串                                                             |
| $                        | 匹配字符串的结束                  | .exe$               | 可以匹配.exe 结尾的字符串                                                             |
| \\W                      | 匹配非字母/数字/下划线            | b\\Wt               | 可以匹配 b#t / b@t 等<br>但不能匹配 but / b1t / b_t 等                                |
| \\S                      | 匹配非空白字符                    | love\\Syou          | 可以匹配 love#you 等<br>但不能匹配 love you                                           |
| \\D                      | 匹配非数字                        | \\d\\D              | 可以匹配 9a / 3# / 0F 等                                                              |
| \\B                      | 匹配非单词边界                    | \\Bio\\B            |                                                                                       |
| []                       | 匹配来自字符集的任意单一字符      | [aeiou]             | 可以匹配任一元音字母字符                                                              |
| [^]                      | 匹配不在字符集中的任意单一字符    | [^aeiou]            | 可以匹配任一非元音字母字符                                                            |
| \*                       | 匹配 0 次或多次                   | \\w\*               |                                                                                       |
| +                        | 匹配 1 次或多次                   | \\w+                |                                                                                       |
| ?                        | 匹配 0 次或 1 次                  | \\w?                |                                                                                       |
| {N}                      | 匹配 N 次                         | \\w{3}              |                                                                                       |
| {M,}                     | 匹配至少 M 次                     | \\w{3,}             |                                                                                       |
| {M,N}                    | 匹配至少 M 次至多 N 次            | \\w{3,6}            |                                                                                       |
| \|                       | 分支                              | foo\|bar            | 可以匹配 foo 或者 bar                                                                 |
| (?#)                     | 注释                              |                     |                                                                                       |
| (exp)                    | 匹配 exp 并捕获到自动命名的组中   |                     |                                                                                       |
| (?&nbsp;&lt;name&gt;exp) | 匹配 exp 并捕获到名为 name 的组中 |                     |                                                                                       |
| (?:exp)                  | 匹配 exp 但是不捕获匹配的文本     |                     |                                                                                       |
| (?=exp)                  | 匹配 exp 前面的位置               | \\b\\w+(?=ing)      | 可以匹配 I'm dancing 中的 danc                                                        |
| (?<=exp)                 | 匹配 exp 后面的位置               | (?<=\\bdanc)\\w+\\b | 可以匹配 I love dancing and reading 中的第一个 ing                                    |
| (?!exp)                  | 匹配后面不是 exp 的位置           |                     |                                                                                       |
| (?<!exp)                 | 匹配前面不是 exp 的位置           |                     |                                                                                       |
| \*?                      | 重复任意次，但尽可能少重复        | a.\*b<br>a.\*?b     | 将正则表达式应用于 aabab，前者会匹配整个字符串 aabab，后者会匹配 aab 和 ab 两个字符串 |
| +?                       | 重复 1 次或多次，但尽可能少重复   |                     |                                                                                       |
| ??                       | 重复 0 次或 1 次，但尽可能少重复  |                     |                                                                                       |
| {M,N}?                   | 重复 M 到 N 次，但尽可能少重复    |                     |                                                                                       |
| {M,}?                    | 重复 M 次以上，但尽可能少重复     |                     |                                                                                       |

### Python 对正则表达式的支持

Python 提供了`re`模块来支持正则表达式相关操作，下面是`re`模块中的核心函数。

| 函数                                         | 说明                                                                           |
| -------------------------------------------- | ------------------------------------------------------------------------------ |
| compile(pattern, flags=0)                    | 编译正则表达式返回正则表达式对象                                               |
| match(pattern, string, flags=0)              | 用正则表达式匹配字符串 成功返回匹配对象 否则返回 None                          |
| search(pattern, string, flags=0)             | 搜索字符串中第一次出现正则表达式的模式 成功返回匹配对象 否则返回 None          |
| split(pattern, string, maxsplit=0, flags=0)  | 用正则表达式指定的模式分隔符拆分字符串 返回列表                                |
| sub(pattern, repl, string, count=0, flags=0) | 用指定的字符串替换原字符串中与正则表达式匹配的模式 可以用 count 指定替换的次数 |
| fullmatch(pattern, string, flags=0)          | match 函数的完全匹配（从字符串开头到结尾）版本                                 |
| findall(pattern, string, flags=0)            | 查找字符串所有与正则表达式匹配的模式 返回字符串的列表                          |
| finditer(pattern, string, flags=0)           | 查找字符串所有与正则表达式匹配的模式 返回一个迭代器                            |
| purge()                                      | 清除隐式编译的正则表达式的缓存                                                 |
| re.I / re.IGNORECASE                         | 忽略大小写匹配标记                                                             |
| re.M / re.MULTILINE                          | 多行匹配标记                                                                   |

# 图像
