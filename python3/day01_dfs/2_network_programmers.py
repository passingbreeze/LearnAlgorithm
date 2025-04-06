def solution(n, computers):
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

    # DFS를 통해 연결된 모든 컴퓨터를 방문하는 함수
    def dfs(node):
        visited.add(node)
        for i in range(n):
            # 현재 노드와 연결되어 있고, 아직 방문하지 않은 컴퓨터라면
            if computers[node][i] == 1 and i not in visited:
                dfs(i)

    # 모든 컴퓨터에 대해 확인
    for i in range(n):
        # 아직 방문하지 않은 컴퓨터라면 새로운 네트워크 시작
        if i not in visited:
            dfs(i)
            answer += 1

    return answer

if __name__ == '__main__':
    input1_nodes, input1_computers = 3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
    print(solution(input1_nodes, input1_computers) == 2)
    input2_nodes, input2_computers = 3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]
    print(solution(input2_nodes, input2_computers) == 1)