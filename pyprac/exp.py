
def expsqr(y,x,n,c) :
    if n<0 :
        return expsqr(y, 1/x, -n, 0)
    elif n == 0 :
        c = 0
        return y,c
    elif n == 1 :
        return x*y,c
    elif n%2 == 0:
        return expsqr(y,x*x,n//2,c+1)
    else :
        return expsqr(x*y,x*x, (n-1)//2, c+2)

def main():
    inpexp = input()
    explist = inpexp.split()
    bel = eval(explist[0])
    exp = eval(explist[1])
    cnt = 0
    result = expsqr(1, bel, exp, cnt)
    print(result[0], result[1])

if __name__ == '__main__':
    main()
