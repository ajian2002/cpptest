n = int(input())
a = []
a = [[0 for i in range(2*n+1)] for i in range(n)]
# print(a)
a[0][n-1] = 1
a[n-1][0] = 1
for i in range(1, n):
    for j in range(1, 2*n):
        a[i][j] = a[i-1][j-1]+a[i-1][j+1]
# print(a)
for i in range(n):
    for j in range(n+i):
        if a[i][j] == 0:
            print(" ", end="")
        else:
            print(a[i][j], end="")
    print(" ")
