#-*-coding:utf-8-*-

def mklist(lst):
    evallst = lst
    for i in range(len(evallst)):
        for j in range(len(evallst[i])):
            evallst[i] = evallst[i][j].split()
    for i in range(len(evallst)):
        for j in range(len(evallst[i])) :
            evallst[i][j] = eval(evallst[i][j])
    return evallst

def main():
    string = []
    while True:
        input_str = input().splitlines()
        if input_str == []:
            break
        else :
            string.append(input_str)
    mat = mklist(string)
    print(mat)

if __name__ == '__main__':
    main()
