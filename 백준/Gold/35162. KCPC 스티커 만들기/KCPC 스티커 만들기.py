import sys
input = sys.stdin.readline
for T in range(int(input())) : 
    K, C, P = map(int, input().split())
    if K+C+P == 1  or  (K and C ==0 and P < 2) or (K and C == 1 and P < min(2*(K-C), 1)): 
        print("N")
    else : 
        print("Y")
    