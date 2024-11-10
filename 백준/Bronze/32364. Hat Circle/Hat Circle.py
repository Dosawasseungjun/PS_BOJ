import sys
input = sys.stdin.readline

N = int(input())
A = []
for i in range(N) :
    A.append(int(input()))
r = 0
for i in range(N//2) : 
    r += 2 if A[i] == A[i+N//2] else 0
print(r)
