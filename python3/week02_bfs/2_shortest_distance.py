from typing import *
from collections import deque

def bfs(maps: List[List[int]], start: tuple, visited: List[List[bool]]) -> int:
    """
    BFS 탐색을 통해 최단 경로를 찾는 함수

    Args:
        maps (List[List[int]]): 맵 정보
        start (tuple): 시작 좌표 (x, y)
        visited (List[List[bool]]): 방문 여부 리스트

    Returns:
        int: 최단 거리
    """
    queue = deque([start])
    visited[start[0]][start[1]] = True
    distance = 1

    while queue:
        for _ in range(len(queue)):
            x, y = queue.popleft()

            # 도착 지점에 도달한 경우
            if x == len(maps) - 1 and y == len(maps[0]) - 1:
                return distance

            # 상하좌우 이동
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy

                # 맵 범위 체크 및 방문 여부 확인
                if 0 <= nx < len(maps) and 0 <= ny < len(maps[0]) and not visited[nx][ny] and maps[nx][ny] != 0:
                    visited[nx][ny] = True
                    queue.append((nx, ny))

        distance += 1

    return -1


def solution(maps: List[List[int]]) -> int:
    visited = [[False] * len(maps[0]) for _ in range(len(maps))]
    answer = bfs(maps, (0, 0), visited)
    return answer


if __name__ == '__main__':
    input1 = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]
    print(solution(input1))
    print(solution(input1) == 11)

    input2 = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]
    print(solution(input2))
    print(solution(input2) == -1)

