#-*-coding:utf-8-*-

def setlist(s):
    k = ""
    for i in range(len(s)) :
        k += "0 "
    k = k.split()
    n = k
    for i in range(len(s)) :
        n[i] = eval(k[i])
    return n

def setscore(s, n, l):
    k = len(s)
    if n<k :
        if (s[n] == "O") :
            l[n] = l[n-1]+1
        else :
            l[n] = 0
        setscore(s, n + 1, l)
    return l


sum = 0
inpscre=input()
scorelist = setlist(inpscre)
score = setscore(inpscre, 0, scorelist)
for i in range(len(inpscre)) :
    sum += score[i]
print(sum)