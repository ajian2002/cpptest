def yue(x, y):
    if x < y:
        x, y = y, x
    yu = 1
    while yu != 0:
        yu = x % y
        if yu == 0:
            return y
        else:
            x = y
            y = yu


def bei(x, y):
    return (x*y/yue(x, y))


x, y = map(int, input().split(","))
print("%d,%d" % (yue(x, y), bei(x, y)))
