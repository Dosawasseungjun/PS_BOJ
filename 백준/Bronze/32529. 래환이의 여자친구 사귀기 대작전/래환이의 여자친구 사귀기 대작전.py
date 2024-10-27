N, M = map(int, input().split())
A = list(map(int, input().split()))
S = 0
R = -1
for i in range(len(A)-1, -1, -1) :
    S += A[i]
    if M <= S : 
        R = i+1
        break
print(R)