N, M = map(int, input().split())
res = [-1]
k = 10000000000
for i in range(N) : 
    A = list(map(int, input().split()))
    for j in range(M) : 
        if A[j] == 1 : 
            continue
        if k > (i+1) + abs((M+1)//2 - (j+1)) :
            k = (i+1) + abs((M+1)//2 - (j+1))
            res = [i+1, j+1]
print(*res)