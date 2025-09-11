N = int(input())
A = list(map(int, input().split()))
B = [[A[i], i] for i in range(N)]
B.sort()
S = sum(A)
R = B[0][0] + B[-1][0] + S
idx = 0
for i in range(N-1) :
    S -= B[i][0]
    if R < B[i+1][0] + B[-1][0] + S :
        R = max(R, B[i+1][0] + B[-1][0] + S)
        idx = i+1
ans = []
for i in range(idx, N) : 
    ans.append(B[i][1] + 1)
print(len(ans))
print(*ans)