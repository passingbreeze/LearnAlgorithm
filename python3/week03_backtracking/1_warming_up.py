from typing import List


def backtrack(start: int, n: int, target_sum: int, current_sum: int, path: List[int], result: List[List[int]]):
    """
    백트래킹으로 합이 target_sum이 되는 부분집합 찾기
    """
    # 종료 조건: 합이 목표와 일치하면 결과에 추가
    if current_sum == target_sum:
        result.append(path.copy())
        return

    # 추가 최적화: 남은 모든 숫자를 더해도 목표에 도달할 수 없는 경우 가지치기
    remaining_sum = (n * (n + 1) // 2) - (start * (start - 1) // 2)
    if current_sum + remaining_sum < target_sum:
        return

    # 기존 가지치기: 합이 이미 목표를 초과한 경우
    if current_sum > target_sum or start > n:
        return

    # 현재 숫자부터 n까지 시도
    for i in range(start, n + 1):
        # 추가 가지치기: 현재 숫자를 추가해도 목표를 초과하는 경우 중단
        if current_sum + i > target_sum:
            break

        path.append(i)
        backtrack(i + 1, n, target_sum, current_sum + i, path, result)
        path.pop()


def solution(n: int) -> List[List[int]]:
    """
    1부터 n까지의 숫자 중에서 합이 10이 되는 모든 부분집합을 찾는 함수
    """
    # 최적화: n이 작을 경우 빠른 처리
    if n < 4:  # 1+2+3+4는 10이므로 n<4이면 결과 없음
        return []

    result = []
    backtrack(1, n, 10, 0, [], result)
    return result


if __name__ == '__main__':
    input1_N = 5
    print(solution(input1_N))
    print(solution(input1_N) == [[1,2,3,4], [1,4,5], [2,3,5]])

    input2_N = 2
    print(solution(input2_N))
    print(solution(input2_N) == [])

    input3_N = 7
    print(solution(input3_N))
    print(solution(input3_N) == [[1,2,3,4], [1,2,7], [1,3,6], [1,4,5], [2,3,5], [3,7], [4,6]])