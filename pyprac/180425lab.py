#-*-coding:utf-8-*-

def findweight(n):
    sum = 0
    for i in str(n):
        sum += int(i)
    return sum

def main():
    line = input()
    words = line.split()
    ns = [0] * len(words) # 문자열 크기만큼의 빈 리스트 만드는 코드
    wg = [0] * len(words)
    i = 0
    for word in words: # list안에서 인자 하나하나는 string
        ns[i] = int(word) # 숫자 '문자열'을 '숫자(여기서는 정수)'로 인식
        if int(word) >= 0:
            wg[i] = findweight(word)
        else:
            print('NEGATIVE')
            return
        i += 1
    result = 0
    for i in range(len(words)):
        temp = wg[i]
        for j in range(i+1, len(words)) :
            if wg[j] >= temp:
                result = ns[j]
    print(result)

if __name__ == '__main__':
    main()
