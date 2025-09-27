for _ in range(int(input())) : 
    N= int(input())
    if N & 1 :
        print(42025 * (10 ** (N-5)))
    else :
        print(2025 * (10 ** (N-4)))