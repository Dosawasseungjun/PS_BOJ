a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
A = a + 2*b + 3*c
B = d + 2*e + 3*f
if A > B : 
    print(1)
elif A == B :
    print(0)
else :
    print(2)
