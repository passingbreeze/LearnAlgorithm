from typing import *
from collections import deque

def bfs(board: List[List[int]], visited: List[List[List[float]]]) -> int:
    board_length = len(board)

    # 방향 정의 (상, 우, 하, 좌)
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    queue = deque()

    # (x, y, 방향, 비용)
    # 시작 위치에서는 아직 방향이 없으므로 우(1)와 하(2) 두 방향으로 초기화
    queue.append((0, 0, 1, 0))  # 오른쪽 방향으로 시작
    queue.append((0, 0, 2, 0))  # 아래쪽 방향으로 시작

    # 시작 위치 방문 처리
    visited[0][0][1] = 0
    visited[0][0][2] = 0

    while queue:
        x, y, direction, cost = queue.popleft()

        # 현재 비용이 이미 갱신된 비용보다 크면 스킵
        if cost > visited[x][y][direction]:
            continue

        # 목적지에 도달한 경우
        if x == board_length - 1 and y == board_length - 1:
            continue

        # 현재 위치에서 4방향으로 이동
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 경계 체크 및 벽 체크
            if 0 <= nx < board_length and 0 <= ny < board_length and board[nx][ny] == 0:
                # 비용 계산: 직선 도로는 100원, 코너는 600원(직선 100 + 코너 추가 500)
                new_cost = cost + 100
                if direction != i:  # 방향이 바뀌는 경우 코너 추가 비용
                    new_cost += 500

                # 더 적은 비용으로 해당 위치에 도달할 수 있다면 갱신
                if new_cost < visited[nx][ny][i]:
                    visited[nx][ny][i] = new_cost
                    queue.append((nx, ny, i, new_cost))

    # 도착 지점에 도달한 모든 방향 중 최소 비용 반환
    return int(min(visited[board_length - 1][board_length - 1]))


def solution(board: List[List[int]]) -> int:
    """
    경주로 건설 최소 비용을 계산하는 함수

    Args:
        board: 경주로를 건설할 지형 정보 (0: 빈칸, 1: 벽)

    Returns:
        경주로 건설 최소 비용
    """
    # visited[x][y][dir] = 해당 위치에 특정 방향으로 도달했을 때의 최소 비용
    visited = [[[float('inf')] * 4 for _ in range(len(board))] for _ in range(len(board))]
    # BFS 시작
    answer = bfs(board, visited)
    return answer


if __name__ == '__main__':

    input1 = [[0,0,0],[0,0,0],[0,0,0]]
    print(solution(input1))
    print(solution(input1) == 900)

    input2 = [[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]
    print(solution(input2))
    print(solution(input2) == 3800)

    input3 = [[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]
    print(solution(input3))
    print(solution(input3) == 2100)

    input4 = [[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]
    print(solution(input4))
    print(solution(input4) == 3200)