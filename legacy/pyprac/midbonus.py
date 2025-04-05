#-*-coding:utf-8-*-

def findprime(n):
    if n<2 :
        return False
    for i in range(2,n):
        if n%i == 0 :
            return False
    return True

def setlist(n):
    plist = list(filter(findprime, [x for x in range(n)]))
    sublist = list(map(lambda x:n-x, plist))
    sublist2 = list(filter(findprime, sublist))
    getlist = []
    for i in range(len(sublist)):
        for j in range(len(sublist2)):
            if sublist[i]+sublist2[j] == n :
                mkpair = (sublist[i], sublist2[j])
                getlist.append(mkpair)
    print(getlist)

def main():
    a = int(input())
    setlist(a)

if __name__ == '__main__':
    main()