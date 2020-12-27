
def jiecheng(i):
    if i == 1 or i == 0:
        return 1
    else:
        return i*jiecheng(i-1)
