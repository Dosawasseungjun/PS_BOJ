n, m = map(int, input().split())
mn = 1_000_000_001
s = 0
for i in range(n) :
    b = list(map(int, input().split()))
    s += sum(b)
    mn = min(mn, min(b))
print(s - mn)