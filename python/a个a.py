n = int(input())
s = int('9'*n)+1
pp = [0, 1,  pow(2, 5), pow(3, 5), pow(4, 5), pow(5, 5), pow(6, 5),
      pow(7, 5), pow(8, 5), pow(9, 5)]
for i in range(1, s):
    p = str(i)
    sum = 0
    for j in range(len(p)):
        sum += pp[int(p[j])]
    if (sum == i):
        print(i)
