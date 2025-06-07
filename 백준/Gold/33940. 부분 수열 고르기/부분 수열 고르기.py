N, a, d, M = map(int, input().split())
L, X = 0, 0
for l in range(N+1, 0, -1) :
    x = M - a*l+l*d
    if x % d == 0 :
        x //= d
    else : continue

    if (1+(1+l-1)) * l // 2 <= x <= (N + (N - l +1)) * l // 2 : 
        X = x
        L = l
        break
if L :
    print(L)
    C =[i for i in range(0, l+1)]
    D = x - (1 + l)*l//2
    for i in range(l, 0, -1) :
        V = N - l + i
        delta = min(D, V - C[i])
        C[i] += delta
        D -= delta
        if D == 0 :
            break
    R = []
    for i in range(1, l+1) :
        R.append(a + d*(C[i]-1))
    print(*R)
else :
    print(-1)