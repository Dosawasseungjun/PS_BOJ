import sys
input = sys.stdin.readline

N = int(input())
ps = [0, 1]
for i in range(2, N+2) :
    op, x, y = map(int, input().split())
    if op == 1 :
        if ps[y] - ps[x-1] == y - x + 1 :
            print("Yes")
            ps.append(ps[-1] + 1)
        else : 
            print("No")
            ps.append(ps[-1])
    else : 
        if ps[y] - ps[x-1] == 0 :
            print("Yes")
            ps.append(ps[-1]+1)
        else : 
            print("No")
            ps.append(ps[-1])

            