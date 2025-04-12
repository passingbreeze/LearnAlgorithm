from typing import *

INFO_MAX_LENGTH = 11

def dfs(idx: int, appeach_infos: List[int], left: int, ryan: List[int], max_diff: int, max_ryan: List[int]) -> tuple:
    """
    DFS를 사용하여 최적의 화살 배치를 찾는 함수

    Args:
        idx: 현재 검토 중인 인덱스 (점수 = 10 - idx)
        appeach_infos: 어피치가 맞힌 과녁 점수 개수 배열
        left: 남은 화살 수
        ryan: 현재까지의 라이언 화살 배치
        max_diff: 현재까지의 최대 점수 차이
        max_ryan: 현재까지의 최적 화살 배치

    Returns:
        tuple: (최대 점수 차이, 최적 화살 배치)
    """
    # 기저 사례: 모든 점수대를 검토했거나 화살을 다 쏜 경우
    if idx > INFO_MAX_LENGTH or left == 0:
        # 남은 화살이 있으면 0점에 모두 할당
        if left > 0:
            ryan[10] += left

        # 라이언과 어피치의 점수 계산
        ryan_score = appeach_score = 0
        for i in range(11):
            if ryan[i] > appeach_infos[i]:
                ryan_score += (10 - i)
            elif appeach_infos[i] > 0:
                appeach_score += (10 - i)

        diff = ryan_score - appeach_score

        # 현재 최대 점수 차이보다 크면 업데이트
        if diff > max_diff:
            max_diff = diff
            max_ryan = ryan[:]

        # 점수 차이가 같은 경우, 낮은 점수를 더 많이 맞힌 경우를 선택
        elif diff == max_diff and diff > 0:
            for i in range(10, -1, -1):
                if ryan[i] > max_ryan[i]:
                    max_ryan = ryan[:]
                    break
                elif ryan[i] < max_ryan[i]:
                    break

        # 화살을 0점에 할당했던 것을 원복
        if left > 0:
            ryan[10] -= left

        return max_diff, max_ryan

    # 현재 점수에 화살을 쏘는 경우 (어피치보다 1발 더 쏴서 점수 획득)
    if left > appeach_infos[idx]:
        ryan[idx] = appeach_infos[idx] + 1
        new_max_diff, new_max_ryan = dfs(idx + 1, appeach_infos, left - ryan[idx], ryan, max_diff, max_ryan)
        if new_max_diff > max_diff or (new_max_diff == max_diff and new_max_ryan != [-1]):
            max_diff, max_ryan = new_max_diff, new_max_ryan
        ryan[idx] = 0  # 백트래킹

    # 현재 점수에 화살을 쏘지 않는 경우
    ryan[idx] = 0
    new_max_diff, new_max_ryan = dfs(idx + 1, appeach_infos, left, ryan, max_diff, max_ryan)
    if new_max_diff > max_diff or (new_max_diff == max_diff and new_max_ryan != [-1]):
        max_diff, max_ryan = new_max_diff, new_max_ryan

    return max_diff, max_ryan


def solution(n: int, info: List[int]) -> List[int]:
    """
    라이언이 어피치를 이기기 위한 최적의 화살 배치를 찾는 함수

    Args:
        n: 라이언이 쏠 수 있는 화살의 개수
        info: 어피치가 맞힌 과녁 점수 개수 배열 [10점 개수, 9점 개수, ..., 0점 개수]

    Returns:
        라이언이 맞춰야 하는 과녁 점수 개수 배열, 이길 수 없는 경우 [-1]
    """
    ryans_turn = [0] * (INFO_MAX_LENGTH) # 라이언의 화살 배치 초기화

    # DFS 호출하여 최적 화살 배치 찾기
    max_diff, max_ryan = dfs(0, info, n, ryans_turn, 0, [-1])

    # 라이언이 이길 수 없는 경우
    if max_diff <= 0:
        return [-1]

    return max_ryan


if __name__ == '__main__':
    input1, input1_infos = 5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]
    print(solution(input1, input1_infos))
    print(solution(input1, input1_infos) == [0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0])

    input2, input2_infos = 1, [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    print(solution(input2, input2_infos))
    print(solution(input2, input2_infos) == [-1])

    input3, input3_infos = 9, [0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1]
    print(solution(input3, input3_infos))
    print(solution(input3, input3_infos) == [1, 1, 2, 0, 1, 2, 2, 0, 0, 0, 0])

    input4, input4_infos = 10, [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]
    print(solution(input4, input4_infos))
    print(solution(input4, input4_infos) == [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2])