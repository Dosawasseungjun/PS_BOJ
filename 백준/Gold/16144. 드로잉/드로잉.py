import sys
input = sys.stdin.readline

N = int(input())
B = list(map(int, input().split()))
G = []
for i, b in enumerate(B, 1) : 
    G.append([-i, b, 0, 2*i -1])
    G.append([-i, b+1, 1, 2*i])
P = []
# a = g1*b+y1과 a = g2*b+y2
for g1, y1, k1, idx1 in G :
    for g2, y2, k2, idx2 in G :
        if g1 == g2 or idx1 >= idx2 : continue
        b = (y1 - y2) / (g2 - g1)
        if b < 0 : continue
        P.append([g1*b+y1, b, idx1, idx2])
R = set()
for a, b, i, j in P : 
    ok = True
    for g, y, k, idx in G : 
        if i == idx or j == idx : continue
        if k and a > g*b + y: 
            ok = False
        if k == 0 and a < g*b + y :
            ok = False
    if ok : R.add((a, b))
ok = True if len(R) else False
if len(R) == 1 : 
    (a, b) = list(R)[0]
    if b==0 : ok = False
    for g, y, k, idx in G : 
        if k and a >= g*b + y: 
            ok = False
        if k == 0 and a < g*b + y :
            ok = False
print("pass" if ok else "fail")