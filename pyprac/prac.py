#-*-coding:utf-8-*-
import sys
import datetime
import random

class cal :
    def __init__(self,lst):
        self.a = lst[0]
        self.b = lst[1]
        self.c = lst[2]
    def printcal(self):
        print((self.a+self.b)%(self.c))
        print((self.a%self.c + self.b%self.c) % (self.c))
        print((self.a * self.b % self.c) % (self.c))
        print((self.a % self.c * self.b % self.c) % (self.c))

def main():
   a = [4,5,6]
   b = a
   b.pop()
   print(a, b)


if __name__ == '__main__':
    main()