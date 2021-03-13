[Python学习笔记 生成式和生成器
](https://blog.csdn.net/dark_cy/article/details/99577679)

raise 引发自定义异常
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

断言与自定义异常
```
s=input()
try:
    assert len(s)<=5
    print(s)
except AssertionError:
    print("assert error")
```

