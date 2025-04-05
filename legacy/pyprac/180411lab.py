#-*-coding:utf-8-*-

index = 0
inpspr = input()
strlst = inpspr.split()
string = inpspr.replace(" ","")
for i in range(len(string)) :
    for j in range(len(strlst)):
        if (strlst[j].isalpha() == False):
            print("ERROR")
            break
        elif (strlst[j].isupper() == True):
            print("ERROR")
            break
    max = string.count(string[i])
    for k in range(i+1,len(string)):
        if (max < string.count(string[k])) :
            max = string.count(string[k])
            index = k
            break
        else :
            index = i
    break
print(string[index])



