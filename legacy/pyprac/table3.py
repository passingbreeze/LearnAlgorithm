#-*-coding:utf-8-*-

def repeat(c,n):
    s = c*n
    print(s, end=c)

# def cont():
#     repeat("|     ", 6)
#     print("|")
#
# def underline():
#     repeat("+-----", 6)
#     print("+")

def table(n):
    if n>0:
        repeat("|", 6)
        repeat(" ", 6)
        repeat("|", 6)
        repeat("+-----", 6)
        table(n-1)

n = eval(input())
print("+-----+-----+-----+-----+-----+-----+")
print("|     | MON | TUE | WED | THU | FRI |")
print("+-----+-----+-----+-----+-----+-----+")
table(n)
