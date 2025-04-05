#-*-coding:utf-8-*-

def sumscore(s, n, l):
    k = len(s)
    p = l
    if n<k :
        if (s[n] == "O") :
            p += 1
        sumscore(s, n + 1, p)
    return p

result = 0
sum = 0
inpscre=input()
result = sumscore(inpscre, 0, sum)

print(result)