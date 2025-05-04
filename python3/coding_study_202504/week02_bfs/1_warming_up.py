from typing import *
from collections import deque

def bfs(input_graph: Dict[int, List[int]], start: int) -> List[int]:
    """
    BFS 탐색을 통해 그래프를 순회하는 함수

    Args:
        input_graph (Dict): 그래프 정보
        start (int): 시작 노드

    Returns:
        List[int]: BFS 탐색 결과
    """
    visited = {start}
    queue = deque([start])
    result = [start]

    while queue:
        node = queue.popleft()
        for neighbor in input_graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
                result.append(neighbor)

    return result

def solution(input_graph: List[Tuple[int,int]], start: int) -> List[int]:
    adj_list = {}
    for u, v in input_graph:
        if u not in adj_list:
            adj_list[u] = []
        adj_list[u].append(v)
        if v not in adj_list:
            adj_list[v] = []
    return bfs(adj_list, start)

if __name__ == '__main__': # Test Case
    input1 = [(1,2), (1,3), (2,4), (2,5), (3,6), (3,7), (4,8), (5,8),(6,9), (7,9)]
    input1_start = 1
    print(solution(input1, input1_start))
    print(solution(input1, input1_start) == [1,2,3,4,5,6,7,8,9])

    input2 = [(0,1), (1,2), (2,3), (3,4), (4,5), (5,0)]
    input2_start = 1
    print(solution(input2, input2_start))
    print(solution(input2, input2_start) == [1,2,3,4,5,0])
