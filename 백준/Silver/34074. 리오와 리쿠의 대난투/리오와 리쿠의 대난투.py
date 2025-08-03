N, M = map(int, input().split())
x = int(1E9)
if N == M == 1 : 
    print(-1)
elif N == 1 : 
    if M == 2 : 
        print(3)
        print(1, 4)
    else :
        print(M)
        print(*([i for i in range(1, M)] + [x]))
else : 
    print(*([i for i in range(1, N)] + [x]))
    print(*([i for i in range(N, N+M)]))