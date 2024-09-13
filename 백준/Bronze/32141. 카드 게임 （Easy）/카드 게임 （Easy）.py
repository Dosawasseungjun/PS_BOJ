N, H = map(int, input().split())
a = list(map(int, input().split()))
res = 0
ok = False
for k in a : 
    H -= k
    res += 1
    if H <= 0 : 
        ok = True
        break
if ok : print(res)
else : print(-1)