N = int(input())
A = list(map(int, input().split()))
f = True
for i in range(N) :
    if (i & 1 and A[i] & 1) or (i % 2 == 0 and A[i] % 2 == 0):
        f = False
print("YES" if f else "NO")
        