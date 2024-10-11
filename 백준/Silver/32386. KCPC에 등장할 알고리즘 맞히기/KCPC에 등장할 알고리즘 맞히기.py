import sys
input = sys.stdin.readline

N = int(input())
D = dict()
for i in range(N) : 
    A = list(input().split())
    for i in range(2, len(A)) : 
        if A[i] in D : 
            D[A[i]] += 1
        else :
            D[A[i]] = 1
ans = ""
k = 0
for key, value in D.items() : 
    if k < value : 
        ans = key
        k = value
    elif k == value : 
        ans = "-1"
print(ans)
        