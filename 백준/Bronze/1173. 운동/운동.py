N, m , M, T, R = map(int, input().split())
if m + T > M :
    print(-1)
else :
    k ,t = 0, 0
    x = m
    while k < N :
        if x + T <= M :
            x += T
            k += 1
        else :
            x = max(m, x-R)
        t += 1        
    print(t)
