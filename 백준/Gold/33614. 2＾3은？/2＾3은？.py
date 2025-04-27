for _ in range(int(input())) : 
    p, q, r = map(int, input().split())
    print(p + min(q, r) - 1)