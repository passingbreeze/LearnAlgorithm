#-*-coding:utf-8-*-

index = 0
inpspr = input()
string = inpspr.replace(" ","")
for i in range(len(string)) :
    if ((string.isalpha() == False) or (string.islower()==False)):
            print("ERROR")
            break
    else :
        max = string.count(string[i])
        for k in range(i+1,len(string)):
            if (max < string.count(string[k])) :
                max = string.count(string[k])
                index = k
        print(string[index])
    break




