W = input()
S = input()
U = [0 for i in range(26)]
R = ""
for w in W : 
    if U[ord(w) - ord('A')] :
        continue
    U[ord(w) - ord('A')] = 1
    R += w
for i in range(26) :
    if U[i] == 0 : 
        R += chr(ord('A') + i)
res = ""
for s in S : 
    idx = ord(s)-ord('A')
    res += R[idx]
print(res)