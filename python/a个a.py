n = int(input())
maxstr = ""
max = 0
b = n
for i in range(0, b):
    s = str(input().lstrip())
    if (max < len(s)):
        max = len(s)
        maxstr = s
print("length=%d" % len(maxstr))
