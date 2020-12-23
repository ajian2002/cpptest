x = int(input())
n = x*x
s = []
for i in range(x):
    s.append([])
    s[i].extend([0]*x)
zz = 1
le = 0
ri = x-1
temp = x-1
while n > 0:

    for i in range(x-zz, zz-1, -1):
        s[ri][i] = n
        n -= 1
    for i in range(x-zz, zz-1, -1):
        s[i][le] = n
        n -= 1
    for i in range(zz-1, x-zz):
        s[le][i] = n
        n -= 1
    for i in range(zz-1, x-zz):
        s[i][ri] = n
        n -= 1
    le += 1
    ri -= 1
    temp -= 2
    zz += 1


for i in range(x):
    for j in range(x-1):
        print("%-3d " % s[i][j], end="")
    print(s[i][j+1])
