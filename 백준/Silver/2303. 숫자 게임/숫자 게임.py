from itertools import combinations
N = int(input())
A = [0 for _ in range(N)]
for i in range(N) : 
    B = list(map(int, input().split()))
    for a, b, c in combinations(B, 3) :
        A[i] = max(A[i], (a+b+c)%10)
R, idx = 0, 0
for i in range(N) : 
    if R <= A[i]  :
        R = A[i]
        idx = i+1
print(idx)
    
        