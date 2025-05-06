from typing import *


def binary_transition(s: str) -> List[int]:
    total_zeros = 0
    trans_count = 0

    while s != "1":
        # 현재 문자열의 0의 개수와 1의 개수를 한 번에 계산
        zeros = s.count('0')
        ones = len(s) - zeros

        # 0의 개수를 누적
        total_zeros += zeros

        # 다음 문자열은 1의 개수의 이진 표현
        s = bin(ones)[2:]

        # 변환 횟수 증가
        trans_count += 1

    return [trans_count, total_zeros]

def solution(s: str) -> List[int]:
    return binary_transition(s)


if __name__ == '__main__':
    input1_s = "110010101001"
    print(solution(input1_s))
    print(solution(input1_s) == [3, 8])

    input2_s = "01110"
    print(solution(input2_s))
    print(solution(input2_s) == [3, 3])

    input3_s = "1111111"
    print(solution(input3_s))
    print(solution(input3_s) == [4, 1])
