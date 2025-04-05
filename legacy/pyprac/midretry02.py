#-*-coding:utf-8-*-

def repeat(c, n):
    for i in range(n):
        print(c, end="")

def star(c, n):
    for i in range(1, n+1):
        repeat(" ", n-i)
        repeat(c, 2*i-1)
        print()

def main():
    num = int(input())
    shape = input()
    star(shape, num)

if __name__ == '__main__':
    main()