#-*-coding:utf-8-*-
from sys import *
from math import *

class point:
    def __init__(self, pl):
        self.x = pl[0]
        self.y = pl[1]

    def __str__(self):
        return '('+str(self.x)+','+str(self.y)+')'

    def __repr__(self):
        return 'point'+'('+str(self.x)+','+str(self.y)+')'

    def dist(self,other):
        d = sqrt((self.x-other.x)**2 + (self.y-other.y)**2)
        return d

def findmax(pl):
    findlist = []
    for i in range(len(pl)):
        for j in range(len(pl)):
            findlist.append(pl[i].dist(pl[j]))
    findlist.sort()
    findlist.reverse()
    return findlist[0]

def main():
    fl = [x.split() for x in stdin]
    for i in range(len(fl)):
        for j in range(len(fl[0])):
            fl[i][j] = float(fl[i][j])
    pl = [point(fl[x]) for x in range(len(fl))]
    findmax(pl)
    print("%.2f"%findmax(pl))

if __name__ == '__main__':
    main()