import sys
input = sys.stdin.readline
N = int(input())
x, y = 0, 0
for i in range(N) : 
    a, b = map(int, input().split())
    if a > b : a, b = b, a
    x = max(x, a)
    y = max(y, b)
print(x * y)