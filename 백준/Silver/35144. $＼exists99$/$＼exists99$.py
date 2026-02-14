import math
a, b = map(int, input().split())
if a == b : 
    print("INF")
else : 
    if a > b : a, b = b, a
    p, q = a * a, b - a
    g = math.gcd(p, q)
    print(p // g, q // g)
    