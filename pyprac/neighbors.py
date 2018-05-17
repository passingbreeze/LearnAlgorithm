#-*-coding:utf-8-*-

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
    evallst = lst
    for i in range(len(evallst)):
        for j in range(len(evallst[i])):
            evallst[i] = evallst[i][j].split()
    for i in range(len(evallst)):
        for j in range(len(evallst[i])) :
            evallst[i][j] = eval(evallst[i][j])
    return evallst

def neighmat(vacmat, nummat):
    for i in range(len(nummat)):
        for j in range(len(nummat[i])):
            vacmat[i][j]=nummat[i][j]
    print(vacmat)
    return vacmat

def main():
    input_num = []
    while True:
        input_str = input()
        if input_str == "":
            break
        else :
            str = input_str.splitlines()
            input_num.append(str)
    
    mat = mkevalmat(input_num)
    row = len(mat)
    col = len(mat[0])
    mat2 = vacantmatrix(row+2,col+2)
    mat2 = neighmat(mat2, mat)

if __name__ == '__main__':
    main()
