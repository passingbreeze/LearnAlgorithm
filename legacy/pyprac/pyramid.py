def repeat(c, n):
    for i in range(n):
        print(c, end="")

def star(n, c):
    for i in range(n):
        repeat(' ', n-i)
        repeat(c, 2*i-1)
        print()

if __name__ == '__main__':
    n = eval(input())
    c = input()
    star(n,c)