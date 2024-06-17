N, L = map(int, input().split())
T = 0
pre = 0
for i in range(N) :
    D, R, G = map(int, input().split())
    M = R + G
    T += D - pre
    pre = D
    if T % M < R : 
        T += R - T % M
print(T + L - pre)
    