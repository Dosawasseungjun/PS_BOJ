N, M = map(int, input().split())
if N == 0:
    print(0)
else :
    A = list(map(int, input().split()))
    k = 0
    res = 1
    for a in A :
        if k + a <= M : 
            k += a
        else :
            res += 1
            k = a
    print(res)