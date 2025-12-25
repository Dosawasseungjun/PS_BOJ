a, b, c, d = map(int, input().split())
if max(a+b, c) <= d :
    print("~.~")
elif a+b <= d :
    print("Shuttle")
elif c <= d :
    print("Walk")
else :
    print("T.T")