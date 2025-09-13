import math
for T in range(int(input())) : 
    N, A, B, C = map(int, input().split())
    L = math.lcm(A, B, C)
    x, y, z = L // A, L // B, L // C
    s = x + y + z
    if N % s == 0 :
        R = L * (N // s) - N
        print(R if R >= 0 else -1)
    else :
        print(-1)
