import sys
input = sys.stdin.readline
for i in range(int(input())) : 
    n, m, L, R, U, D = map(int, input().split())
    w, h = 1, 1
    tl, tr, tu, td = 0, 0, 0, 0
    if L == 0 : 
        if R : 
            w = m
            d = m-1
            tr = (d+R-1) // R
    elif R == 0 :
        w = m
        d = m - 1
        tl = (d+L-1)//L
    else : 
        w = m
        tl = tr = (m+L+R-2) // (L+R)

    if U == 0 :
        if D : 
            h = n
            td = (n+D-2) // D
    elif D == 0 :
        h = n
        tu = (n+U-2) // U
    else : 
        h = n
        td = tu = (n-2+U+D) // (U+D)
    W = w * h
    T = max(tl+tu, tl+td, tr+tu, tr+td)
    print(W, T)