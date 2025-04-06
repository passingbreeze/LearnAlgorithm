from typing import *

def dfs(node: int, visited: Set[int], computers: List[List[int]], n: int):
    """
        DFS 탐색을 통해 연결된 컴퓨터를 방문하는 함수

        Args:
            node: 현재 노드
            visited: 방문한 노드 집합
            computers: 컴퓨터 간의 연결 정보를 담은 2차원 배열
            n: 컴퓨터의 개수
    """
    visited.add(node)
    for i in range(n):
        # 현재 노드와 연결되어 있고, 아직 방문하지 않은 컴퓨터라면, 재귀적으로 DFS 탐색
        if computers[node][i] == 1 and i not in visited:
            dfs(i, visited, computers, n)

def solution(n: int, computers: List[List[int]]) -> int:
    """
        DFS를 활용하여 네트워크 개수를 찾는 함수

        Args:
            n: 컴퓨터의 개수
            computers: 컴퓨터 간의 연결 정보를 담은 2차원 배열

        Returns:
            네트워크 개수
        """
    visited = set()
    answer = 0

    # 모든 컴퓨터에 대해 확인
    for i in range(n):
        # 아직 방문하지 않은 컴퓨터라면 새로운 네트워크 시작
        if i not in visited:
            dfs(i, visited, computers, n)
            answer += 1

    return answer

if __name__ == '__main__':
    input1_nodes, input1_computers = 3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
    print(solution(input1_nodes, input1_computers) == 2)
    input2_nodes, input2_computers = 3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]
    print(solution(input2_nodes, input2_computers) == 1)