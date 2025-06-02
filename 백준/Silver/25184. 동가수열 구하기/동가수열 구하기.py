N = int(input())
d = N//2
A = []
a = N - N//2
b = N
while len(A) < N : 
    if a >= 1 : 
        A.append(a)
        a -= 1
    if b > N - N//2 :
        A.append(b)
        b -= 1
print(*A)