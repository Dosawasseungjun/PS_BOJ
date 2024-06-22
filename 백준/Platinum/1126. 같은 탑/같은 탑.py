N = int(input())
H = [0] + list(map(int, input().split()))
dp = [[-1 for _ in range(500_001)] for _ in range(N+1)]
dp[0][0] = 0
for i in range(1, N+1) : 
    for j in range(500_001) : 
        if dp[i-1][j] != -1 : 
            dp[i][j + H[i]] = max(dp[i][j + H[i]], dp[i-1][j] + H[i])
            dp[i][abs(j - H[i])] = max(dp[i][abs(j - H[i])], max(dp[i-1][j] - j + H[i], dp[i-1][j]))
            dp[i][j] = max(dp[i][j], dp[i-1][j])
print(dp[N][0] if dp[N][0] else -1)
