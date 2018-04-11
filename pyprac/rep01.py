def star(n):
    if n>0:
        print("*", end = " ")
        star(n-1)
    else:
        print()

star(10)