def isPalindrome(s: str, begin: int, end: int) -> bool:
    while begin < end:
        if s[begin] != s[end]:
            return False
        begin += 1
        end -= 1
    return True


def solution(s: str) -> bool:
    begin, end = 0, len(s) - 1
    while begin < end:
        if s[begin] == s[end]:
            begin += 1
            end -= 1
        else:
            is_palin_from_begin = isPalindrome(s, begin + 1, end)
            is_palin_from_end = isPalindrome(s, begin, end - 1)
            return is_palin_from_begin or is_palin_from_end
    return True

if __name__ == '__main__':
    # Test cases
    input1_test = "aba"
    print(solution(input1_test))  # Expected output: True
    print(solution(input1_test) == True)

    input2_test = "abca"
    print(solution(input2_test))  # Expected output: True
    print(solution(input2_test) == True)

    input3_test = "abc"
    print(solution(input3_test))  # Expected output: False
    print(solution(input3_test) == False)

    input4_test = "a"
    print(solution(input4_test))  # Expected output: True
    print(solution(input4_test) == True)

    input5_test = "aa"
    print(solution(input5_test))  # Expected output: True
    print(solution(input5_test) == True)

    input6_test = "abbca"
    print(solution(input6_test))  # Expected output: True
    print(solution(input6_test) == True)

    input7_test = "zryxeededexyz"
    print(solution(input7_test))  # Expected output: False
    print(solution(input7_test) == False)
