for _ in range(int(input())) :
    W, N = map(int, input().split())
    trash = []
    for i in range(N) :
        trash.append(list(map(int, input().split())))
    res = 0
    for i in range(N) :
        cap = W
        for j in range(i, N) :
            if trash[j][1] == 0 : continue
            if cap - trash[j][1] <= 0 :
                res += 2 * trash[j][0]
                if cap - trash[j][1] == 0 :
                    trash[j][1] = 0
                break
            cap -= trash[j][1]
            trash[j][1] = 0
            if j == N-1 :
                res += 2 * trash[N-1][0]
                break
                
    print(res)
