N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = [0 for _ in range(N)]
D = [0 for _ in range(N)]
for i, k in enumerate(B, 1) :
    if i - C[k-1] <= A[k-1] : 
        if i - C[k-1] == 1 and D[k-1] == 1 :
            D[k-1] = 0
    else : 
        D[k-1] = 1
    C[k-1] = i
for i, a in enumerate(A) :
    x = M+1-C[i]
    if x > a :
        D[i] = 1
print(D.count(1))