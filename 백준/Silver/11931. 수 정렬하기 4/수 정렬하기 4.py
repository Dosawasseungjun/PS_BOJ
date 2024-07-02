import sys
input = sys.stdin.readline
N = int(input())
A = []
for i in range(N) :
    A.append(int(input()))
A.sort(reverse = True)
for a in A :
    print(a)