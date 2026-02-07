import sys
input = sys.stdin.readline

mod = int(1E9) + 7
for _ in range(int(input())) :
    G, D = map(int, input().split())
    dp = [0 for _ in range(G+1)]
    dp[0] = 1
    for i in range(1, G+1) : 
        for j in range(1, D+1) : 
            if 0 <= i -j < G: 
                dp[i] += dp[i-j]
                dp[i] %= mod
    print(dp[G]) 
