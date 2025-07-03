A, B, C = map(int, input().split())
S, V = map(int, input().split())
L = int(input())
d = (250 - L) * 100
if d <= V * C * 30 : 
    m = (d + C - 1) // C
    print(m)
else :
    d -= V * C * 30
    if d <= S * B * 30 :
        m = (d + B - 1) // B + 30 * V
        print(m)
    else : 
        d -= S * B * 30
        m = (d + A - 1) // A + 30 * (V + S)
        print(m)