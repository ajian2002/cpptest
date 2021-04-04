import math


def Freq(line):
    d = {}
    for i in line:
        if(i not in d):
            d.update({i: 1})
        else:
            d[i] += 1
    s = sorted(d.keys())
    print(len(s))
    for i in s:
        print(i, " = %d" % d[i])


def jiecheng(i):
    if i == 1 or i == 0:
        return 1
    else:
        return i*jiecheng(i-1)


def funcos(eps, x):
    vaule = 0.0000
    j = 0
    k = 0
    temp = pow(-1, j) * pow(x, k)/jiecheng(k)
    j += 1
    k += 2
    while abs(temp) >= eps:
        vaule += temp
        temp = pow(-1, j) * pow(x, k)*1.0000/jiecheng(k)
        j += 1
        k += 2

    return vaule


def fib(n):
    if(n == 1 or n == 0):
        return 1
    return fib(n-1)+fib(n-2)


def PrintFN(m, n):
    d = []
    for i in range(0, 25):
        d.append(fib(i))
    s = []
    for i in range(m, n+1):
        if(i in d):
            s.append(i)
    return s


def bonus(sales):
    s = sales
    if(sales <= 10000):
        return 5000
    elif(sales <= 20000 and sales > 10000):
        return s*0.10+5000
    elif (sales <= 50000 and sales > 20000):
        return s*0.15+5000
    elif (sales <= 100000 and sales > 50000):
        return s*0.20+5000
    elif (sales > 100000):
        return s*0.25+5000


def prime(p):
    i = p
    if (i == 2):
        return True
    if (i == 1):
        return False
    else:
        for j in range(2, i):
            if (i % j == 0):
                return False
        return True


def PrimeSum(m, n):
    sum = 0
    for i in range(m, n+1):
        if(prime(i) == True):
            sum += i
    return sum


def fenjei(n):
    d = []
    if(n == 1):
        d.append(1)
        return d
    if(n == 2):
        return d
    for i in range(2, n, 1):
        if(n % i == 0 and i > n/i):
            break
        if(n % i == 0 and i == n/i):
            d.append(i)
            break
        if(n % i == 0 and i < n/i):
            d.append(i)
            d.append(n/i)
    return d


def wan(n):
    m = pow(10, n-1)
    n = pow(10, n)
    count = 0
    summ = []
    for i in range(m, n):
        d = fenjei(i)
        if(len(d) != 0 and sum(d) == i-1) or sum(d) == 1:
            count += 1
            summ.append(i)
    return count, summ


n = int(input())
x, lst = wan(n)
print(x)
print(lst)
