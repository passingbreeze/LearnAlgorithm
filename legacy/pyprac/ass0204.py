#-*-coding:utf-8-*-

# recursive

def line(n):
    if (n>0):
        print("+---", end="")
        line(n-1)
    else:
        print("+")

def cont(n):
    if (n>0):
        print("|   ", end="")
        cont(n-1)
    else:
        print("|")

def table(r,c):
    if (r>0):
        line(c)
        cont(c)
        table(r-1,c)
    else :
        line(c)

a = eval(input())
b = eval(input())
table(a,b)
