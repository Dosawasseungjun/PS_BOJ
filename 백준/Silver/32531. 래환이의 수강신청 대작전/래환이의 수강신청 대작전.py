N, M = map(int, input().split())
A = [0 for _ in range(M+1)]
for i in range(N-1) : 
    s = list(map(int, input().split()))
    for k in s[1:] :
        A[k] |= (1 << i)
D = {}
for i in range(1, M+1) :
    if A[i] in D : 
        D[A[i]] += 1
    else :
        D[A[i]] = 1
ok = True
res = 1
for key, val in D.items() : 
    if val >= 3 :
        ok = False
        break
    else :
        res *= 2
print(res)

