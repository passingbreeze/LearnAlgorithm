from typing import *


def dfs(k: int, dungeons: List[List[int]], visited: List[bool], depth: int) -> int:
    """
    백트래킹을 사용해 최대 던전 탐험 수를 찾는 함수

    Args:
        k: 현재 피로도
        dungeons: 던전 정보 (최소 피로도, 소모 피로도)
        visited: 던전 방문 여부
        depth: 현재까지 탐험한 던전 수

    Returns:
        최대 던전 탐험 수
    """
    max_depth = depth

    # 모든 던전을 확인
    for i, dungeon in enumerate(dungeons):
        # 아직 방문하지 않은 던전이고, 피로도가 충분한 경우
        min_fatigue, consume_fatigue = dungeon
        if not visited[i] and k >= min_fatigue:
            visited[i] = True  # 방문 표시
            # 다음 던전 탐험 (깊이 우선 탐색)
            max_depth = max(max_depth, dfs(k - consume_fatigue, dungeons, visited, depth + 1))
            visited[i] = False  # 백트래킹

    return max_depth


def solution(k: int, dungeons: List[List[int]]) -> int:
    visited = [False] * len(dungeons)
    return dfs(k, dungeons, visited, 0)

if __name__ == '__main__':
    input1_k, input1_dungeons = 80, [[80,20],[50,40],[30,10]]
    print(solution(input1_k, input1_dungeons))
    print(solution(input1_k, input1_dungeons) == 3)
