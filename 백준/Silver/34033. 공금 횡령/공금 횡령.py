import sys
input = sys.stdin.readline

N, M = map(int, input().split())
D = {}
for i in range(N) : 
    s, k = input().split()
    D[s] = int(k)
res = 0
for i in range(M) :
    s, k = input().split()
    k = int(k)
    if k * 100 > D[s] * 105 :
        res += 1
print(res)