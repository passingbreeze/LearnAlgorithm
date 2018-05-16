def vacantmatrix(r,c):
    m = [[0]*c for i in range(r)]
    return m

def mkmatrix(r,c):
    mat = vacantmatrix(r, c)
    mat = [[eval(x) for x in input().split()]for y in range(r)]
    return mat

def transpose(mat):
    row = len(mat)
    col = len(mat[0])
    mat2 = vacantmatrix(col, row)
    for i in range(row):
        for j in range(col):
            mat2[j][i] = mat[i][j]
    return mat2

def countmatval(mat):
    row = len(mat)
    col = len(mat[0])
    count = 0
    total = 0
    for i in range(row):
        for j in range(col):
            if mat[i].count(mat[i][j])==1:
                count += 1
        if count == col :
            total += 1
        count = 0
    mat2 = transpose(mat)
    row = len(mat2)
    col = len(mat2[0])
    for i in range(row) :
        for j in range(col) :
            if mat2[i].count(mat2[i][j]) == 1:
                count += 1
        if count == col:
            total += 1
        count = 0
    return total


def main():
    rowcol = input()
    rowcol = rowcol.split()
    row = eval(rowcol[0])
    col = eval(rowcol[1])
    vmat = mkmatrix(row, col)
    num = countmatval(vmat)
    print(num)

if __name__ == '__main__':
    main()