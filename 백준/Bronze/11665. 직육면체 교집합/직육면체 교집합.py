N = int(input())
X1, Y1, Z1, X2, Y2, Z2 = 0, 0, 0, 1001, 1001, 1001
for i in range(N) :
    x1, y1, z1, x2, y2, z2 = map(int, input().split())
    X1 = max(x1, X1)
    Y1 = max(y1, Y1)
    Z1 = max(z1, Z1)
    X2 = min(x2, X2)
    Y2 = min(y2, Y2)
    Z2 = min(z2, Z2)
if X2 > X1 and Y2 > Y1 and Z2 > Z1 :
    print((X2 - X1)*(Y2-Y1)*(Z2-Z1))
else :
    print(0)