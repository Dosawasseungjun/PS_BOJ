import sys
input = sys.stdin.readline

for _ in range(int(input())) : 
    N = int(input())
    A = list(map(int, input().split()))
    R = [N] * ((1 << N) + 1)
    P = list(map(int, input().split()))

    e = N-1
    k = 0
    for i in range(e, -1, -1) : 
        st = k
        k += (1 << i)
        for j in range(st, k) : 
            R[A[j]] = i

    B = [0] * ((1 << N) + 1)
    L = [0] * ((1 << N) + 1)

    for i in range(1, (1 << N) +1) : 
        L[i] = (1 << N) - (1 << (N - R[i])) + 1

    x = A.pop()
    B[x] = 1
    tmp = [x]
    for i in range(1, N+1) : 
        tmp_nxt = []
        if i == N : 
            for j in range((1 << N), 0, -1) : 
                tmp_nxt.append(j)
        else : 
            for j in range((1 << i)) : 
                tmp_nxt.append(A.pop())
        for j in range((1 << i)) :
            if tmp_nxt[j] != tmp[j // 2] :
                B[tmp_nxt[j]] = B[tmp[j // 2]] + 1
        tmp = tmp_nxt

    for i in range(1, P[0]+1) :
        print(f"Player {P[i]} can be ranked as high as {B[P[i]]} or as low as {L[P[i]]}.")
    print()
