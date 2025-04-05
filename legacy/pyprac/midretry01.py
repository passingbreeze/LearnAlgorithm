#-*-coding:utf-8-*-
def mkstr(astr,bstr, num):
    fstr = ""
    for i in range(1, num+1):
        if i%2 > 0 :
            fstr += astr
        elif i%2 == 0:
            fstr += bstr
        fstr += " "
    flist = fstr.split()
    flist.reverse()
    return flist[0]


def main():
    n = eval(input())
    a = input()
    b = input()
    print(mkstr(a,b,n))

if __name__ == '__main__':
    main()