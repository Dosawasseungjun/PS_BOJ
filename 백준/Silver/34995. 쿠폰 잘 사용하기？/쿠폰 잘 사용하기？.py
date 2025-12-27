N, S = input().split()
N = int(N)
K = input()
if len(S) < len(K) : 
    print(-1)
elif len(S) > len(K) : 
    R = ""
    for c in S : 
        if c == '?' : 
            R += '1'
        else : 
            R += c
    print(R)
else : 
    R = [c for c in S]
    x = 0 # 같음 : 0 S가 큼 : 1 K가 큼 : 2
    for i in range(N) :
        if S[i] == '?' : 
            if K[i] == '9' : 
                R[i] = '9'
            else :
                x = 1 
                R[i] = '9'
                break 
        elif S[i] < K[i] : 
            x = 2
            break
        elif S[i] > K[i] : 
            x = 1
            break
    for i in range(N) : 
        if R[i] == '?' : 
            R[i] = '9'
    print("".join(R) if x < 2 else -1)
