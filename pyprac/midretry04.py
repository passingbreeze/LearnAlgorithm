#-*-coding:utf-8-*-

def ret_rev(str):
    return "".join(reversed(str))

def isPalindrome(word):
    if len(word)%2==0 :
        return word[:len(word)//2] == ret_rev(word[len(word)//2:])
    else :
        return word[:len(word)//2] == ret_rev(word[(len(word)//2)+1:])

def mkPalindrome(word):
    for i in range(0, len(word)):
        if isPalindrome(word[i:]):
            return word + ret_rev(word[:i])
    return word + ret_rev(word)

def main():
    word = input().upper()
    if (isPalindrome(word)) :
        print(word)
    else :
        print(mkPalindrome(word))


if __name__ == '__main__':
    main()