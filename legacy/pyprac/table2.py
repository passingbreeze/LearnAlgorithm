#-*-coding:utf-8-*-

def cont():
    print("|     |     |     |     |     |     |")
    print("|     |     |     |     |     |     |")

def underline():
    print("+-----+-----+-----+-----+-----+-----+")

def table(n):
    if n>0:
        cont()
        underline()
        table(n-1)

n = eval(input())
print("+-----+-----+-----+-----+-----+-----+")
print("|     | MON | TUE | WED | THU | FRI |")
print("+-----+-----+-----+-----+-----+-----+")
table(n)
