N = int(input())
T = int(input())
A = list(map(int, input().split()))
now = 0
for b in map(int, input().split()) :
    now = (now + b-1) % (2*N)
    print(A[now], end=" ")