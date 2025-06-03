N = int(input())
A, B = [], []
x = 1
if N % 3 == 2 : 
    A.append(x)
    x += 1
    B.append(x)
    x += 1
for i in range(x, N+1, 3) :
    if i + 2 > N : break
    A.append(i)
    A.append(i+1)
    B.append(i+2)
print(len(A))
print(*A)
print(len(B))
print(*B)