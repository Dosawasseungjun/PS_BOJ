N = int(input())
dp = [[0 for _ in range(21)] for _ in range(N)] 
a = list(map(int, input().split()))
dp[0][a[0]] = 1
for i in range(1, N-1) :
    for j in range(21) :
        if dp[i-1][j] : 
            if j + a[i] <= 20 :
                dp[i][j+a[i]] += dp[i-1][j]
            if j - a[i] >= 0 :
                dp[i][j-a[i]] += dp[i-1][j]
print(dp[N-2][a[N-1]])