N, C = map(int, input().split())
res = 100000000000
for i in range(N) : 
    p, d, v = map(int, input().split())
    res = min(res, p + d + v*C)
print(res)