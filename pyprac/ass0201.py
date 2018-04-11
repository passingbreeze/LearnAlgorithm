#-*-coding:utf-8-*-

def repeat(c,n):
    s = c*n
    return s

def hor(n):
    if n>0:
        print(repeat("+---",n), end='+')
        print()

def ver(n):
    if n>0:
        print(repeat("|   ",n), end='|')
        print()

def table(r,c):
    if r>0:
        hor(c)
        ver(c)
        table(r-1,c)
    else:
        hor(c)

a = eval(input())
b = eval(input())
table(a,b)