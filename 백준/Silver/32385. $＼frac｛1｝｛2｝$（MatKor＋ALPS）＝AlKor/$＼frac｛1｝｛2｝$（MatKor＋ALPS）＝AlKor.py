N = int(input())
R = []
if N & 1 : R += [0]
for i in range(1, N//2+1) :
    R += [N*i] + [N*(N+1-i)]
R += [sum(R)//N]
print(*R)