def sol() : 
    N = int(input())
    if N < 6 : 
        print(-1) 
    else :
        if N & 1 : 
            print(4)
            print(1, N//2, N//2+1, N-2)
        else : 
            print(3)
            print(1, N//2, N-2)

for _ in range(int(input())) : 
    sol()