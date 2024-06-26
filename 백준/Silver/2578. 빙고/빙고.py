A =  [list(map(int, input().split())) for _ in range(5)] 
B = [list(map(int, input().split())) for _ in range(5)] 
C = [[0 for _ in range(5)] for _ in range(5)]
bingo = 0

def cntbingo(c) :
    bg = 0
    for i in range(5) :
        if sum(c[i]) == 5 : bg += 1
    for j in range(5) :
        sm = 0
        for i in range(5) :
            sm += c[i][j]
        if sm == 5 : bg += 1
    sm = 0
    for i in range(5) :
        sm += c[i][i]
    if sm == 5 : bg += 1
    sm = 0
    for i in range(5) :
        sm += c[4-i][i]
    if sm == 5 : bg += 1

    return bg

res = 0
cnt = 0
for b in B :
    for x in b :
        cnt += 1
        for i in range(5) :
            for j in range(5) :
                if A[i][j] == x : 
                    C[i][j] = 1
                    if res == 0 and cntbingo(C) >= 3 :
                        res = cnt
                    break
print(res)
