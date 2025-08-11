N, M = map(int, input().split())
G = [[0 for _ in range(101)] for _ in range(101)]
for i in range(N) :
    a, b, c, d = map(int, input().split()) 
    for ii in range(a, c+1) :
        for jj in range(b, d+1) :
            G[ii][jj] += 1
res = 0
for i in range(1, 101) :
    for j in range(1, 101) :
        if G[i][j] > M : 
            res += 1
print(res)