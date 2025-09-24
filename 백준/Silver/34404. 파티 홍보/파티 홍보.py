N = int(input())
A = []
for i in range(N) : 
    x, y, p, q = map(int, input().split())
    A.append([x, y, p, q])
a, b = map(int, input().split())
res = N
for x, y, p, q in A : 
    mx, my = (x+p)/2, (y+q)/2
    if my < a*mx+b :
        res -= 1
print(res)