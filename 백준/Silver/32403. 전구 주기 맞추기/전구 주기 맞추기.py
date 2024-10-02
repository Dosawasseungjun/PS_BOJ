N, T = map(int, input().split())
A = list(map(int, input().split()))
r = 0
for a in A :
    k = 2001
    for i in range(1, 2000) : 
        if T % i == 0 :
            k = min(k, abs(a-i))
    r += k
print(r)