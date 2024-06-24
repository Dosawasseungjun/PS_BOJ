import sys
input = sys.stdin.readline

N = int(input())
if N == 0 :
    print(0)
    sys.exit()
X = [[] for _ in range(N)]

L = [0 for _ in range(N)]
for i in range(N) :
    s = input().rstrip()
    year = int(s[0:4])
    month = int(s[5:7])
    day = int(s[8:10])
    hour = int(s[11:13])
    minute = int(s[14:16])
    sec = int(s[17:19])
    l = int(s[20 : ])
    X[i] = [year, month, day, hour, minute, sec]
    L[i] = l

P = [0.0 for _ in range(N)]
month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for idx ,[y, mo, d, h, mi, s] in enumerate(X) :

    k = month[:]
    if y == 2020 : k[1] += 1
    D1 = sum(k[:mo-1]) + d
    S1 = h * 60 * 60 + mi * 60 + s
    for i in range(2019, y) :
        if i == 2020 :
            D1 += 366
        else : 
            D1 += 365

    k2 = month[:]
    if X[-1][0] == 2020 : k2[1] += 1
    D2 = sum(k2[:X[-1][1]-1]) + X[-1][2]
    S2 = X[-1][3] * 60 * 60 + X[-1][4] * 60 + X[-1][5]
    for i in range(2019, X[-1][0]) :
        if i == 2020 :
            D2 += 366
        else :
            D2 += 365
    
    tn_minus_ti = (D2 - D1) + (S2 - S1) /  (24 * 60 * 60)
    P[idx] = max((0.5) ** (tn_minus_ti / 365), (0.9) ** (N-idx-1))

res = 0
for i in range(N) :
    res += P[i] * L[i]
res /= sum(P)
print(int(res+0.5))