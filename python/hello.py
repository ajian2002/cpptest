a, b, c = map(int, input().split())
if a == 0:
    if b == 0:
        print("No")
    else:
        x = -c*1.000/b
        print("%0.2f" % x)
else:
    delt = (b**2-4*a*c)
    if delt < 0:
        print("No")
    elif delt > 0:
        delt = delt**(1/2)
        x2 = (delt-b)*1.00/(2*a)
        print("%0.2f" % x2, end=" ")
        x1 = (-b-delt)*1.00/(2*a)
        print("%.2f" % x1)
    else:
        x = -b*1.00/(2*a)
        print("%0.2f" % x)
