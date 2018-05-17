#-*-coding:utf-8-*-

import sys

def vacantmatrix(r,c):
    m = [[0]*c for i in range(r)]
    return m

def transpose(mat):
    row = len(mat)
    col = len(mat[0])
    mat2 = vacantmatrix(col, row)
    for i in range(row):
        for j in range(col):
            mat2[j][i] = mat[i][j]
    return mat2

def mkevalmat(lst):
    for i in range(len(lst)):
        for j in range(len(lst[i])) :
            lst[i][j] = eval(lst[i][j])
    return lst

def neighmat(vacmat, nummat):
    for i in range(1, (len(vacmat)-1)):
        for j in range(1, (len(vacmat[i])-1)):
            vacmat[i][j]=nummat[i-1][j-1]
    return vacmat

def callist(weimat, mat):
    row = len(mat)
    col = len(mat[0])
    for i in range(1, (len(mat)-1)):
        for j in range(1, (len(mat[i])-1)):
            weimat[i-1][j-1] = mat[i-1][j-1]+mat[i-1][j]+mat[i-1][j+1]+mat[i][j-1]+mat[i][j+1]+mat[i+1][j-1]+mat[i+1][j]+mat[i+1][j+1]
    return weimat

def findmax(lst):
    row = len(lst)
    col = len(lst[0])
    templist = [0]*(row*col)
    i = 0
    for r in range(row):
        for c in range(col):
            templist[i] = lst[r][c]
            i+=1
    templist.sort()
    templist.reverse()
    max = templist[0]
    for r in range(row):
        for c in range(col):
            if lst[r][c] == max :
                print(c, r)
                return

def main():
    mat = [line.split() for line in sys.stdin]
    mat = mkevalmat(mat)
    row = len(mat)
    col = len(mat[0])
    mat2 = vacantmatrix(row+2,col+2)
    mat2 = neighmat(mat2, mat)
    weighmat = vacantmatrix(row,col)
    result = callist(weighmat, mat2)
    findmax(result)

if __name__ == '__main__':
    main()
