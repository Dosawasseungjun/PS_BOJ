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
dq.clear()
for i in range(N) : 
    if S[i] == 'A' : dq.append(i)
    elif S[i] == 'B' and dq: 
        R += 1
        dq.popleft()
print(min(R, S.count("B")))