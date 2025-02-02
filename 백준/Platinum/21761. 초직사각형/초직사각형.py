import sys
input = sys.stdin.readline

N, K = map(int, input().split())
P = list(map(int, input().split()))
import heapq
hq = [[] for _ in range(4)]
cards = [0 for _ in range(N)]
for i in range(N) :
    T, U = input().split()
    U = int(U)
    heapq.heappush(hq[ord(T)-ord('A')], [-U, i])
    cards[i] = [T, U]

for i in range(K) : 
    X = []
    for j in range(4) : 
        tmp = 1
        for k in range(4) : 
            if j == k :
                tmp *= P[j] + ((-hq[j][0][0]) if hq[j] else 0)
            else : 
                tmp *= P[k]
        X.append(tmp)
    idx = X.index(max(X))
    ru, ridx = heapq.heappop(hq[idx])
    P[idx] += -ru
    print(*cards[ridx])