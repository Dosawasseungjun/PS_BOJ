N = int(input())
S, T = 0, 0
for i in range(1, N+1) : 
    T += 5
    S += T
print(7*S)