N = int(input())
b = list(map(int, input().split()))
a = [0] * N
a[0] = b[0]
if a[0] == 0 :
    print(-1)
else :
    s = a[0]
    ok = True
    for i in range(1, N) :
        if (b[i] + 1) * i < s : 
            a[i] = b[i] + 1
        elif b[i] * i >= s : 
            a[i] = b[i]
        else :
            ok = False
        if a[i] == 0 : 
            ok = False
        s += a[i]
    if ok  : 
        print(*a)
    else :
        print(-1)
