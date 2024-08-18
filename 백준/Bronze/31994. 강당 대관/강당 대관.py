A = []
for i in range(7) :
    S, K = input().split()
    A.append([S, int(K)])
A.sort(key=lambda x : x[1])
print(A[-1][0])