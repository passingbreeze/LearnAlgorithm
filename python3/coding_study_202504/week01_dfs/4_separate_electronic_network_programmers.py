from typing import *

def wires_to_graph(n: int, wires: List[List[int]]) -> List[List[int]]:
    """
    주어진 간선 리스트를 기반으로 그래프를 인접 리스트 형태로 변환하는 함수

    Args:
        n (int): 노드 갯수
        wires (List[List[int]]): 간선 리스트, [[u, v], [v, w], ...]

    Returns:
        Dict[int, List[int]]: 인접 리스트
    """
    graph = [[] for _ in range(n + 1)]
    for u, v in wires:
        graph[u].append(v)
        graph[v].append(u)
    return graph

def solution(n: int, wires: List[List[int]]) -> int:
    answer = n
    graph = wires_to_graph(n, wires)

    # 모든 간선을 제거한 상태에서 DFS를 통해 각 노드의 개수를 세는 방법
    for v1, v2 in wires:
        visited = [False] * (n + 1)
        visited[v1] = True
        stack = [v1]
        cnt = 0

        # DFS 탐색
        while stack:
            node = stack.pop()
            cnt += 1
            for neighbor in graph[node]:
                if not visited[neighbor] and neighbor != v2:
                    visited[neighbor] = True
                    stack.append(neighbor)

        # 각 간선을 제거한 상태에서의 노드 개수를 세고, 그 차이를 계산
        answer = min(answer, abs(cnt - (n - cnt)))

    return answer

if __name__ == '__main__':
    input1, input1_wires= 9, [[1, 3], [2, 3], [3, 4], [4, 5], [4, 6], [4, 7], [7, 8], [7, 9]]
    print(solution(input1, input1_wires) == 3)
    input2, input2_wires = 4, [[1, 2], [2, 3], [3, 4]]
    print(solution(input2, input2_wires) == 0)
    input3, input3_wires = 7, [[1, 2], [2, 7], [3, 7], [3, 4], [4, 5], [6, 7]]
    print(solution(input3, input3_wires) == 1)
