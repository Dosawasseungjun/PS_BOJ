import sys
input = sys.stdin.readline

N, M = map(int, input().split())
G = [[-1 for _ in range(N+1)] for _ in range(4)]
for i in range(M) :
    x, y, t = map(int, input().split())
    G[x][y] = t
INF = 1_000_001
dp = [[[INF for _ in range(8)] for _ in range(8)] for _ in range(N+2)] 
# dp[i][j][k] : i번째 블록까지 봤고 i-1까지는 꽉 채워져 있으며 j는 i의 상태, k는 i+1의 상태
if G[1][1] and G[3][1] != 1: 
    dp[1][3][1] = 1
if G[3][1] and G[1][1] != 1: 
    dp[1][6][4] = 1
if G[3][1] and G[1][1] : 
    dp[1][7][5] = 2

for i in range(2, N+1) :
    for j in range(8) :
        for k in range(8) :
            if dp[i-1][j][k] != INF : 
                if G[1][i] and G[3][i] != 1 and (j == 6 or j == 7):
                    dp[i][k | 3][1] = min(dp[i][k | 3][1], dp[i-1][j][k] + 1)
                if G[3][i] and G[1][i] != 1 and (j == 3 or j == 7):
                    dp[i][k | 6][4] = min(dp[i][k | 6][4], dp[i-1][j][k] + 1)
                if G[1][i] and G[3][i] and (j==2 or j ==3 or j==6 or j == 7):
                    dp[i][k | 7][5] = min(dp[i][k | 7][5], dp[i-1][j][k] + 2)

res = min(dp[N][7])
print(res if res != INF else -1)