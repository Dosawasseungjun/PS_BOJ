N, D, p = map(int, input().split())
A = list(map(int, input().split()))
R = 0
for i, a in enumerate(A) : 
    k = a // D
    r = a % D
    R += k
    if r : 
        x = D - r
        R += 1
        if i+1 < N :
            A[i+1] -= min(x * p // 100, A[i+1])
print(R)