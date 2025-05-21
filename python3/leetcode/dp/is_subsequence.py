
def solution(s: str, t: str) -> bool:
    s_len, t_len = len(s), len(t)
    dp = [[False] * (t_len + 1) for _ in range(s_len + 1)]

    # 빈 문자열 초기화
    for j in range(t_len + 1):
        dp[0][j] = True

    # DP 테이블 채우기
    for i in range(1, s_len + 1):
        for j in range(1, t_len + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = dp[i][j - 1]

    return dp[s_len][t_len]


if __name__ == '__main__':
    input1_s, input1_t = "abc", "ahbgdc"
    print(solution(input1_s, input1_t))
    print(solution(input1_s, input1_t) == True)

    input2_s, input2_t = "axc", "ahbgdc"
    print(solution(input2_s, input2_t))
    print(solution(input2_s, input2_t) == False)