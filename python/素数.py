a, b = eval(input())
m = 1
for i in range(a, b + 1):
    if (i == 1 or i == 2):
        print(i)
        continue
    else:
        for j in range(2, i):
            if (i % j == 0):
                m = 0
                break
            else:
                m = 1
        if (m == 1):
            print(i)
            m = 1
