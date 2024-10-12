l, r, x = map(int, input().split())
c = [0 for _ in range(1024)]
for i in range(l, r+1) : 
    c[i | x] = 1
r = 0
while c[r] : 
    r += 1
print(r)