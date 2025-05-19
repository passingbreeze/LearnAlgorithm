
def generate_parentheses(left: int, right: int, total: int, current:list[str], answer: list[str]):
    if left == total and right == total:
        answer.append(''.join(current))
        return

    if left < total:
        current.append("(")
        generate_parentheses(left + 1, right, total, current, answer)
        current.pop()

    if left > right:
        current.append(")")
        generate_parentheses(left, right + 1, total, current, answer)
        current.pop()

def solution(n: int) -> list[str]:
    answer = []
    generate_parentheses(0, 0, n, [], answer)
    return sorted(answer)

if __name__ == '__main__':
    input1_n = 3
    print(solution(input1_n))
    print(solution(input1_n) == ["((()))", "(()())", "(())()", "()(())", "()()()"])

    input2_n = 1
    print(solution(input2_n))
    print(solution(input2_n) == ["()"])

    input3_n = 4
    print(solution(input3_n))
    print(solution(input3_n) == ["(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()()(())", "()()()()"])

    input4_n = 2
    print(solution(input4_n))
    print(solution(input4_n) == ["(())", "()()"])