a, b = map(int, input().split())
c, d = map(int, input().split())
e, f = map(int, input().split())
if (a == c == e and min(b, d) < f < max(b, d)) or (b == d == f and min(a, c) < e < max(a, c)) : 
    print(2)
elif a == c or b == d : 
    print(0)
else : 
    print(1)