N = int(input())
A = [(N+2)//2]
l, r = A[0]-1, A[0]+1
while l > 0 or r <= N :
    if l > 0 : 
        A.append(l)
        l -= 1
    if r <= N : 
        A.append(r)
        r += 1
print(*A)
    