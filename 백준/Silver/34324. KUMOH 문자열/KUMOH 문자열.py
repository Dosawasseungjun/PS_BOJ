N = int(input())
S = [input() for _ in range(N)]
res = 0
for i in range(N) :
    T = ""
    y,x = i, 0
    while y >= 0 and x < 1000:
        if x < len(S[y]) : T += S[y][x]
        y -= 1
        x += 1
    X = T.count("KUMOH")
    Y = T[::-1].count("KUMOH")
    res += max(X, Y)

for i in range(1, 1000) :
    T = ""
    y, x = N-1, i
    while y >= 0 and x < 1000:
        if x < len(S[y]) : T += S[y][x]
        y -= 1
        x += 1
    X = T.count("KUMOH")
    Y = T[::-1].count("KUMOH")
    res += max(X, Y)
print(res)