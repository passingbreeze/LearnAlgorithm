#-*-coding:utf-8-*-
from functools import reduce

def main():
    inputnum = [eval(i) for i in input().split()]
    mat = [[eval(c) for c in input().split()] for r in range(inputnum[0])]
    xlist = [c for r in range(inputnum[0]) for c in range(inputnum[1]) if(mat[r][c] == inputnum[2] or mat[r][c] == inputnum[3])]
    ylist = [r for r in range(inputnum[0]) for c in range(inputnum[1]) if(mat[r][c] == inputnum[2] or mat[r][c] == inputnum[3])]
    print(abs(reduce(lambda x,y:x-y, xlist))+abs(reduce(lambda x,y:x-y, ylist)))

if __name__ == '__main__':
    main()