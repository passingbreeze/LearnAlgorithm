#-*-coding:utf-8-*-

def table(n):
    if n>0:
        print("|     |     |     |     |     |     |")
        print("|     |     |     |     |     |     |")
        print("+-----+-----+-----+-----+-----+-----+")
        table(n-1)

n = eval(input())
print("+-----+-----+-----+-----+-----+-----+")
print("|     | MON | TUE | WED | THU | FRI |")
print("+-----+-----+-----+-----+-----+-----+")
table(n)
