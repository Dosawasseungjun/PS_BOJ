N, k = map(int, input().split())
A = list(map(int, input().split()))
f = True
for i in range(k) : 
    p, q = set(), set()
    for j in range(i, N, k) :
        p.add(j)
        q.add(A[j])
    if p != q : 
        f = False
print("Yes" if f else "No")
        