N = int(input())
A = list(map(int, input().split()))
S = sum(A)
O = S
A.sort()
for i in range(1, N) :
    k = A[i-1] * A[i]
    S = max(S, O - A[i-1] - A[i] + 2*k)
print(S)