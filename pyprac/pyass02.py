#-*-coding:utf-8-*-

def repeat(c,n):
    s = c*n
    return s

def table(r,c):
    if r>0:
        print(repeat("+---", c)+'+')
        print(repeat("|   ", c)+'|')
        table(r-1,c)
    else :
        print(repeat("+---", c)+'+')

a = eval(input())
b = eval(input())
table(a,b)