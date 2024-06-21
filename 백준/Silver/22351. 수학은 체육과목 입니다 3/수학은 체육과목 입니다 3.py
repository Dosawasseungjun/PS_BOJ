S = input()
n = len(S)
st, ed = "", ""
for i in range(1, n+1) :
    ok = True
    nxt = str(int(S[:i]) + 1)
    ii = 0
    while i + ii < n :
        if S[i+ii : i+ii +len(nxt)]  != nxt : 
            ok = False
        ii += len(nxt)
        nxt = str(int(nxt) + 1)
    
    if ok : 
        st = S[:i]
        ed = str(int(nxt)-1)
        break

print(st, ed)