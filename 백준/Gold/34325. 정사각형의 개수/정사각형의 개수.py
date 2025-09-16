N, K = map(int, input().split())
res = 0
mod = int(1E9+7)
A = []
for i in range(1, N+1) : 
    x, a_i = 0, 0
    if i & 1 : 
        x = (i-1)//2
        a_i = (i*i + 4*x*x) % mod 
    else : 
        x = (i-2) // 2
        a_i = (i*i + 4*x*(x+1))%mod
    A.append(a_i)
for i in range(1, N+1) :
    res = (res + A[N-i]* pow(K, i, mod) % mod) % mod
print(res)

    