while 1 : 
    try :
        N, B, M = map(float, input().split())
        i = 0
        while N*((1 + B / 100) ** i) < M :
            i += 1
        print(i)
    except :
        break