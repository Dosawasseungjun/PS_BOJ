for _ in range(int(input())) : 
    L, R, S = map(int, input().split())
    d1 = S - L
    d2 = R - S
    if d1 < d2 : 
        print(2 * d1 + 1)
    else : 
        print(2 * d2)