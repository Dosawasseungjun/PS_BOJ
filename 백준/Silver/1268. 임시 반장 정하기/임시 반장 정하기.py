import sys
input = sys.stdin.readline

N = int(input())
a = [[] for _ in range(N)]
for i in range(N) :
    a[i] = list(map(int, input().split()))

b = [set() for _ in range(N)]

for i in range(N) :
    for j in range(5) :
        for k in range(N) :
            if i == k : continue
            if a[i][j] == a[k][j] :
                b[i].add(k)
c = [len(set(x)) for x in b]
print(c.index(max(c)) + 1)
        