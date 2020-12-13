a, b, c = map(int, input().split(' '))
delt = pow(b*b-4*a*c, 0.5)
if a == 0:
    if b == 0:
        print("NO")
    else:
        x = -c*1.000/b
        print("%.2f" % x)
else:
    if delt == 0:
        x = -b*1.00/2/a
        print("%.2f" % x)
    elif delt < 0:
        print("NO")
    else:
        x2 = (delt-b)*1.00/2/a
        print("%.2f" % x2, end=" ")
        x1 = (-b-delt)*1.00/2/a
        print("%.2f" % x1)
