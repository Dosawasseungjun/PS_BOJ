import sys
input = sys.stdin.readline

N = int(input())
D = []
for i in range(N) : 
    t = []
    for _ in range(5) :
        t.append(input().rstrip())
    D.append(t)

mx = 36
res = [-1, -1]
for i in range(N) :
    for j in range(i+1, N) :
        diff = 0
        for k in range(5) :
            for p in range(7)  :
                if D[i][k][p] != D[j][k][p] : 
                    diff += 1
        if diff < mx :
            mx = diff
            res = [i, j]
print(res[0] + 1, res[1] + 1)