import sys
input = sys.stdin.readline

N, M = map(int, input().split())
C = [0] * (N+1)
for i in range(M) : 
    a, b = map(int, input().split())
    C[a] += 1
W = [0] * (M+1)
for i in range(1, N+1) : 
    W[C[i]] += 1
R = 0
for i in range(M+1) : 
    if W[i] == 0 : 
        continue
    R += W[i] - 1
    if i+1 <= M : W[i+1] += W[i] - 1
    else : W.append(W[i] -1 )
while W[-1] > 1 : 
    R += W[-1] -1
    W.append(W[-1] - 1)
print(R)