from typing import List, Dict, Set

def arrange_nodes(input_graph: List[List[str]]) -> Dict[str, List[str]]:
    """
    노드 리스트들을 받아, 한 노드에서의 인접 노드들을 정리하는 함수
    """
    adj_list = {}
    for routes in input_graph:
        if routes[0] not in adj_list:
            adj_list[routes[0]] = [routes[1]]
        else:
            adj_list[routes[0]].append(routes[1])
    return adj_list

def dfs(adj_list: Dict[str, List[str]], start:str, visited: Set[str], stack: List[str]):
    """
    DFS 알고리즘을 구현한 함수
    """
    visited.add(start)
    stack.append(start)
    if start not in adj_list:
        return
    for neighbor in adj_list[start]:
        if neighbor not in visited:
            dfs(adj_list, neighbor, visited, stack)

def solution(input_graph: List[List[str]], start: str) -> List[str]:
    adjacent_list = arrange_nodes(input_graph)
    visited = set()
    result = []
    dfs(adjacent_list, start, visited, result)
    return result

if __name__ == '__main__': # Test Case
    input1 = [['A','B'], ['B', 'C'], ['C', 'D'], ['D', 'E']]
    print(solution(input1, 'A') == ['A', 'B', 'C', 'D', 'E'])
    input2 = [['A','B'], ['A', 'C'], ['B', 'D'], ['B', 'E'], ['C', 'F'], ['E', 'F']]
    print(solution(input2, 'A') == ['A', 'B', 'D', 'E', 'F', 'C'])
