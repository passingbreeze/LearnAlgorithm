
def fizzbuzz(result:list[str], n: int) -> list[str]:
    if n == 0:
        return result
    if n % 3 == 0 and n % 5 == 0:
        result.append("FizzBuzz")
    elif n % 3 == 0:
        result.append("Fizz")
    elif n % 5 == 0:
        result.append("Buzz")
    else:
        result.append(str(n))
    return fizzbuzz(result, n - 1)


def solution(n: int) -> list[str]:
    return fizzbuzz([], n)[::-1]

if __name__ == '__main__':
    input1_n = 3
    print(solution(input1_n))
    print(solution(input1_n) == ["1", "2", "Fizz"])

    input2_n = 5
    print(solution(input2_n))
    print(solution(input2_n) == ["1", "2", "Fizz", "4", "Buzz"])

    input3_n = 15
    print(solution(input3_n))
    print(solution(input3_n) == ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"])