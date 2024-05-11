import sys
input = sys.stdin.readline
MAX = 10001
G = [[] for _ in range(MAX)]
D = [-1 for _ in range(MAX)]

def dfs(here) : 
    global D, G
    for nxt_v, nxt_w in G[here] :
        if D[nxt_v] != -1 : continue
        D[nxt_v] = D[here] + nxt_w
        dfs(nxt_v)

while True:
    try:
        u, v, w = map(int, input().split())
        G[u].append([v, w])
        G[v].append([u, w])
    except:
        break

D[1] = 0
dfs(1)
k = D.index(max(D))
D = [-1 for _ in range(MAX)]
D[k] = 0
dfs(k)
print(max(D))