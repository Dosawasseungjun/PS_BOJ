N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(N)]
res = 0
for i in range(N-2) : 
    for j in range(M-2) :
        if A[i][j] != B[i][j] :
            res += 1
            for p in range(i, i+3) :
                for q in range(j, j+3) :
                    A[p][q] = '0' if A[p][q] == '1' else '1'
ok = True
for i in range(N) :
    for j in range(M) :
        if A[i][j] != B[i][j] : ok = False
print(res if ok else -1)
