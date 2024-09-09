n, k, t = map(int, input().split())
D = list(map(int, input().split()))
r = 0
for d in D : 
    t = t + d - t + k
    r += abs(t - k)
print(r)