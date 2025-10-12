a, b = map(int, input().split())
p, q = 0, 1
if b & (b - 1) : 
    print(-1)
else : 
    res = ""
    while p < a : 
        if a & q :
            p += q
            res += "G"
        q *= 2
        res += "K"
    while q < b : 
        q *= 2
        res += "K"
    print(res)
    