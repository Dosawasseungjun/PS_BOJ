A, B = map(int, input().split())
R = 0
x, y = 1, 1
for i in range(B) :
    y += A - 2
    x = x + y
print(x)