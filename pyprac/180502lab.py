def calstr(l, dicstr) :
    sum = ""
    result = 0
    for word in l:
        for idx in dicstr.keys():
            if word == dicstr[idx] :
                sum += str(idx)
    result = int(sum)
    return result

def main() :
    calnum = 0
    str1 = input()
    str2 = input()
    list1 = str1.split()
    list2 = str2.split()
    setstr={}
    for idx, count in enumerate(list1) :
        setstr[idx] = count
    calnum = calstr(list2, setstr)
    print(calnum**2)

if __name__ == '__main__':
    main()