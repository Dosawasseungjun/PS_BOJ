N = int(input())
R = 0
for i in range(1, N+1) :
    R += i * (N // i)
print(R)