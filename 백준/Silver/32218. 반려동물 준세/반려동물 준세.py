N = int(input())
A = list(map(int, input().split()))
na = [0 for _ in range(N)]
res = 1
while na != A : 
    for idx, a in enumerate(A) : 
        k = 0
        for i in range(idx+1, N) :
            if a < A[i] : k += 1
        na[idx] = k
    res += 1
    A = na
    na = [0 for _ in range(N)]
print(res)