#-*-coding:utf-8-*-
from math import *  # for using every names in math
from sys import *

def gcd(a,b):
    if a<0 and b<0:
        return -1
    if b==0:
        return a
    return gcd(b, a%b)

def main():
    x = input()
    y = input()
    retv = gcd(x,y)
    if retv >= 0 :
        print(retv)
    else:
        print('cannot calculate')
if __name__ == '__main__':
    main()