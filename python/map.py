#!/usr/bin/env python
# -*- coding:utf-8 -*-
a, b, c = map(int, input().split())
if a == 0:
    if b == 0:
        print("No")
    else:
        print("%0.2f" % (-c/b))
else:
    delta = b**2-4*a*c
    d = delta**(1/2)
    if delta < 0:
        print("No")
    elif delta == 0:
        print("%0.2f" % (-b/(2*a)))
    else:
        max1 = max(((-b)-d)/(2*a), ((-b)+d)/(2*a))
        min1 = min(((-b)-d)/(2*a), ((-b)+d)/(2*a))
        print("%0.2f %0.2f" % (max1, min1))
