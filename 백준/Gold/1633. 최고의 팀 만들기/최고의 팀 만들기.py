A = []
while True:
    try:
        a, b= map(int,input().split())
        A.append([a, b])
    except:
        break
n = len(A)
dp = [[[-1 for _ in range(16)] for _ in range(16)] for _ in range(n)]
dp[0][0][0] = 0
dp[0][1][0] = A[0][0]
dp[0][0][1] = A[0][1]
for i in range(1, n) :
    for j in range(16) :
        for k in range(16) :
            if dp[i-1][j][k] != -1 : 
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k])
                if j < 15 : dp[i][j+1][k] = max(dp[i][j+1][k], dp[i-1][j][k] + A[i][0])
                if k < 15 : dp[i][j][k+1] = max(dp[i][j][k+1], dp[i-1][j][k] + A[i][1])
print(dp[n-1][15][15])