n = int(input())
a = list(map(int,input().split()))
s = int(input())
for i in range(n):
    mx = a[i]
    idx = i
    for j in range(i, min(n,s+i+1)) :
        if mx < a[j] :
            mx = a[j]
            idx = j
    for j in range(idx,i,-1) :
        a[j], a[j-1] = a[j-1],a[j]
    s -= idx - i
print(*a)