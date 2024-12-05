N = int(input())
A = [[x for x in range(N, 0, -1)] for _ in range(2)]
R = []
for i in range(N, 1, -1) :
    while i in A[0][0:i-1] or i in A[1][0:i-1] : 
        for j in range(i-2, -1, -1) : 
            if A[0][j] == i :
                c = 0
                if A[1][j+1] < A[0][j+1] : 
                    c = 1
                R.append([j+1, i, A[c][j+1]])
                A[0][j], A[c][j+1] =  A[c][j+1], A[0][j]
                break
            if A[1][j] == i :
                c = 0
                if A[1][j+1] < A[0][j+1] : 
                    c = 1
                R.append([j+1, i, A[c][j+1]])
                A[1][j], A[c][j+1] =  A[c][j+1], A[1][j]
                break
            
print(len(R))
for [a, b, c] in R : 
    print(a, b, c)