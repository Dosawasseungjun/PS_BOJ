N = int(input())
K = input()
o, e = 0, 0
for k in K :
    if int(k) & 1 : 
        o += 1
    else :
        e += 1
if o > e :
    print(1)
elif o < e :
    print(0)
else : 
    print(-1)