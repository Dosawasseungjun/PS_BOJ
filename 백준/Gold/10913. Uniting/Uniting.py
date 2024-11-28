N = int(input())
A = list(map(int, input().split()))
print((sum(A)**2 - sum([x*x for x in A])) // 2)
mod = int(1E9+7)
R = 1
for i in range(1, N+1) :
    R *= i
    R %= mod
for i in range(1, N) : 
    R *= i
    R %= mod
print(R)