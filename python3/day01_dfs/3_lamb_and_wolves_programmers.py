from typing import List

def array_to_tree(num_nodes: int, edges: List[List[int]]) -> List[List[int]]:
    """
    Edges를 받아서 트리 형태로 변환하는 함수

    Args:
        num_nodes (int): 노드의 개수
        edges (List[List[int]]): 간선 리스트, [[u, v], [v, w], ...]

    Returns:
        List[List[int]]: 트리 형태로 변환된 리스트, [[], [], ...]
    """
    tree = [[] for _ in range(num_nodes)]
    for parent, child in edges:
        tree[parent].append(child)
    return tree

def dfs(info: List[int], tree: List[List[int]], node: int, sheep: int, wolf: int, next_nodes: List[int]) -> int:
    """
    DFS 탐색을 통해 최대 양 수를 계산하는 함수

    Args:
        info (List[int]): 각 노드에 있는 아이가 양인지 늑대인지 정보
        tree (List[List[int]]): 트리 형태로 변환된 리스트
        node (int): 현재 노드
        sheep (int): 현재까지 양의 수
        wolf (int): 현재까지 늑대의 수
        next_nodes (List[int]): 다음 방문할 노드 후보 리스트

    Returns:
        int: 최대 양 수

    """
    # 현재 방문한 노드에 있는 아이가 양인지 늑대인지 확인
    is_wolf = info[node]

    # 늑대라면 늑대 수 증가, 양이라면 양 수 증가
    if is_wolf:
        wolf += 1
    else:
        sheep += 1

    # 늑대 수가 양 수보다 많다면 종료
    if wolf >= sheep:
        return 0

    # 최대 양 수를 초기화
    max_sheep = sheep

    # 다음 방문할 노드 후보를 설정
    next_candidates = next_nodes.copy()
    for child in tree[node]:
        next_candidates.append(child)

    # 현재 노드가 다음 방문 후보에 있다면 제거
    if node in next_candidates:
        next_candidates.remove(node)

    # 다음 노드 후보를 순회하며 DFS 탐색
    for next_node in next_candidates:
        temp_next_nodes = next_candidates.copy()
        temp_next_nodes.remove(next_node)
        max_sheep = max(max_sheep, dfs(info, tree, next_node, sheep, wolf, temp_next_nodes))

    return max_sheep


def solution(info: List[int], edges: List[List[int]]) -> int:
    input_tree = array_to_tree(len(info), edges)
    return dfs(info, input_tree, 0, 0, 0, [])

if __name__ == '__main__':
    input1_info, input1_edges = [0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1], [[0, 1], [1, 2], [1, 4], [0, 8], [8, 7], [9, 10], [9, 11], [4, 3], [6, 5], [4, 6], [8, 9]]
    print(solution(input1_info, input1_edges) == 5)
    input2_info, input2_edges = [0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0], [[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6], [3, 7], [4, 8], [6, 9], [9, 10]]
    print(solution(input1_info, input1_edges) == 5)