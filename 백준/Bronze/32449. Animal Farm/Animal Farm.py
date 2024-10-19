n = int(input())
k = 0
A = []
for i in range(n) : 
    s, f = input().split()
    A.append([s, int(f)])

for s, f in A :
    if s == "pig" : 
        k = max(k, f)
x = k
for s, f in A : 
    if s != "pig" and f < k: 
        x += f
print(x)