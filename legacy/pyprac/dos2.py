# -*- coding: utf-8 -*-

def sqr(x, y):
    f = x * x
    s = y * y
    if f > s:
        return f - s
    elif f < s:
        return s - f
    else:
        return 0

a = eval(input())
b = eval(input())
print(sqr(a, b))
