import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T) : 
    N = int(input())
    A = [input().strip() for _ in range(N)]
    k = 0
    for i in range(1, N) :
        if A[i] == "111" : 
            k ^= 2
        elif A[i] == "110" or A[i] == "011" : 
            k ^= 1
        else : 
            k ^= 0
    print("Yesyes" if k else "Nono")