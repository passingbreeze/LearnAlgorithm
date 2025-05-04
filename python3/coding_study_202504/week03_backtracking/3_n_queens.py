from typing import List

def is_safe(row: int, col: int, board: List[int]) -> bool:
    """
    (row, col) 위치에 퀸을 놓는 것이 안전한지 확인하는 함수 (가지치기 로직).
    이전 행들(0부터 row-1까지)에 놓인 퀸들과의 충돌을 검사한다.
    """
    # 같은 열 검사
    for i in range(row):
        if board[i] == col:
            return False

    # 대각선 검사 (왼쪽 위 대각선과 오른쪽 위 대각선)
    for i in range(row):
        if abs(row - i) == abs(col - board[i]):
            return False

    # 모든 검사를 통과하면 안전함
    return True

def solve_n_queens(row: int, n: int, board: List[int], count: int) -> int:
    """
    백트래킹을 사용하여 N-Queens 문제를 해결하는 재귀 함수.
    """
    # 기저 사례: 모든 행에 퀸을 성공적으로 배치한 경우
    if row == n:
        return count + 1  # 해답 개수 증가하여 반환

    result = count
    # 현재 행(row)의 모든 열(col)에 대해 퀸을 놓아본다.
    for col in range(n):
        # (row, col) 위치가 안전한지(유망한지) 확인
        if is_safe(row, col, board):
            # 안전하다면 퀸을 배치
            board[row] = col  # 현재 행에 퀸을 놓음
            # 다음 행으로 재귀 호출하고 결과를 받아옴
            result = solve_n_queens(row + 1, n, board, result)
            # 명시적인 백트래킹은 필요하지 않음 (다음 반복에서 board[row] 값이 덮어씌워짐)

    return result

def solution(n: int) -> int:
    # board: 각 행(인덱스)에 배치된 퀸의 열 번호를 저장할 리스트
    board = [0] * n

    # 0번 행부터 시작하여 N-Queens 문제 해결
    answer = solve_n_queens(0, n, board, 0)

    return answer

if __name__ == "__main__":
    input1 = 4
    print(solution(input1))
    print(solution(input1) == 2)

    input2 = 8
    print(solution(input2))
    print(solution(input2) == 92)
