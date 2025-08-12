N = int(input())
X = list(map(int, input().split()))
A = [-1] * (2*N)
res = 0
for idx, x in enumerate(X) : 
    if A[x-1] == -1 : 
        A[x-1] = idx
    else : 
        res = max(res, idx - A[x-1] -1)
print(res)