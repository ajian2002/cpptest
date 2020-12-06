a, b, c, d = eval(input())
s = [a, b, c, d]
for i in range(0, 3):
    for j in range(1, 4 - i):
        if s[j] < s[j - 1]:
            s[j], s[j - 1] = s[j - 1], s[j]
print("%d %d %d %d" % (s[0], s[1], s[2], s[3]))
