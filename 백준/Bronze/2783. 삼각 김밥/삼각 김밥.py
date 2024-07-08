X, Y = map(int, input().split())
N = int(input())
res = X * 1000 / Y
for _ in range(N) :
    x, y = map(int, input().split())
    res = min(res, x * 1000 / y)
print(res)
