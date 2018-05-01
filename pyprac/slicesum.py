#-*-coding:utf-8-*-

def setnumlist(sl) :
    nums = sl.split()
    ns = [0] * len(nums)
    i = 0
    for num in nums:
        ns[i] = int(num)
        i+=1
    return ns

def addvector(a,b,slice) :
    al = a[(slice[0]):(slice[len(slice)-1])]
    bl = b[(slice[0]):(slice[len(slice)-1])]
    sl = [0] * (slice[len(slice) - 1] - slice[0])
    sum = 0
    for i in range(len(sl)) :
        sl[i] = al[i] + bl[i]
        sum += sl[i]
    return sum

def subvector(a,b,slice) :
    al = a[(slice[0]):(slice[len(slice) - 1])]
    bl = b[(slice[0]):(slice[len(slice) - 1])]
    sl = [0] * (slice[len(slice)-1] - slice[0])
    sub = 0
    for i in range(len(sl)):
        sl[i] = al[i] - bl[i]
        sub += sl[i]
    return sub

def main():
    a = input()
    o = input()
    b = input()
    c = input()
    al = setnumlist(a)
    bl = setnumlist(b)
    cl = setnumlist(c)
    if (o == '+') :
        print(addvector(al,bl,cl))
    elif (o == '-'):
        print(subvector(al,bl,cl))


if __name__ == '__main__':
    main()
