S = input()
N = len(S)
V = [0]*N
R = 0
from collections import deque
dq = deque()
for i in range(N) : 
    if S[i] == 'B' : dq.append(i)
    elif S[i] == 'C' and dq: 
        R += 1
        V[dq.popleft()] = 1
        V[i] = 1
T = ""
for i in range(N) : 
    if not V[i] : T += S[i]
M = len(T)
dq.clear()
for i in range(M) : 
    if T[i] == 'A' : dq.append(i)
    elif T[i] == 'B' and dq: 
        R += 1
        dq.popleft()
print(R)