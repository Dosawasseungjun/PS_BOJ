for _ in range(int(input())) : 
    __ = input()
    N = int(input())
    S = 0
    for i in range(N) : 
        S += int(input())
    if S % N == 0 :
        print("YES")
    else :
        print("NO")
