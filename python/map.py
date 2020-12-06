x = int(input())
sum1 = 0
sum = 1
for i in range(1, x + 1):
    for j in range(1, i + 1):
        sum *= j
    sum1 += sum
    sum = 1
print(sum1)