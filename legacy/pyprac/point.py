#-*-coding:utf-8-*-
import sys
import math
class point:
    def __init__(self, p):
        self.x = p[0]
        self.y = p[1]
    def __str__(self):
        strx = str("%.2f"%self.x)
        stry = str("%.2f"%self.y)
        return '('+strx+','+stry+')'
    def dist(self):
        d = math.sqrt((self.x)**2+(self.y)**2)
        return d

def findmaxlen(p):
    dl = [p[i].dist() for i in range(len(p))]
    dl.sort()
    dl.reverse()
    return dl[0]

def findmax(p):
    maxd = p[0].dist()
    max = p[0]
    for i in range(len(p)):
        if p[i].dist() > maxd:
            maxd = p[i].dist()
            max = p[i]
    return max

def main():
    a = [x.rstrip() for x in sys.stdin]
    b = []
    for i in range(len(a)):
        c = a[i].split()
        for j in range(len(c)):
            c[j] = float(c[j])
        b.append(c)
    p = [point(b[i]) for i in range(len(b))]
    maxl = findmaxlen(p)
    print(findmax(p))
    print("%.2f" % maxl)

if __name__ == '__main__':
    main()