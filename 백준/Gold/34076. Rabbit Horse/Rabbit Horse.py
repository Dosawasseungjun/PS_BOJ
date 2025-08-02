import copy

N = int(input())
if N < 11 : 
    print('A' * N)
else : 
    S = "RaBbithorse"
    C = {}
    for s in S : 
        if s in C :
            C[s] += 1
        else : 
            C[s] = 1
    res = ""
    A = "Raithorse" # B를 제외한 것
    N -= 11
    ans = 0
    for b in range(N+1) : 
        # B의 개수가 b+2일때
        k = 1
        D = copy.deepcopy(C)
        D['b'] += b
        for i in range(N - b) : 
            D[A[i % len(A)]] += 1
        for key, val in D.items() : 
            if key == 'b' : 
                continue
            k *= val
        k *= (D['b']+1)*(D['b'])//2
        if k > ans : 
            ans = k
            x = ""
            for s in S : 
                x += s * D[s]
            res = x
    print(res)
    