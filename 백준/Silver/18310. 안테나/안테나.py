N = int(input())
A = list(map(int, input().split()))
if N == 1 : 
    print(A[0])
else : 
    A.sort()
    x, y = 0, 0
    for i in range(N) : 
        x += abs(A[i] - A[N//2-1])
        y += abs(A[i] - A[N//2])
    if y < x : 
        print(A[N//2])
    else : 
        print(A[N//2-1])
