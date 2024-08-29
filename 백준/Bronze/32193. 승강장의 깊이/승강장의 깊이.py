import sys
input = sys.stdin.readline

N = int(input())
g, e = 0, 0
for i in range(N) :
    A, B = map(int, input().split())
    g += A
    e += B
    print(g - e)