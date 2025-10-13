A = list(map(int, input().split()))
r = 5
for i in range(5) : 
    m = 0
    for a in A :
        if a in [i+1, i+2, i+3, i+4, i+5] : m += 1
    r = min(r, 5 - m)
print(r)