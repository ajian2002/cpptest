
def jiecheng(i):
    if i == 1 or i == 0:
        return 1
    else:
        return i*jiecheng(i-1)
"""
import operator, functools

# 一行代码定义求阶乘的函数
fac = lambda num: functools.reduce(operator.mul, range(1, num + 1), 1)

# 一行代码定义判断素数的函数
is_prime = lambda x: x > 1 and all(map(lambda f: x % f, range(2, int(x ** 0.5) + 1)))
"""
