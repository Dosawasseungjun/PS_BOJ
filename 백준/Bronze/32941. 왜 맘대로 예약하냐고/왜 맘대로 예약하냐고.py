import sys
input = sys.stdin.readline

T, X = map(int, input().split())
N = int(input())
ok = True
for i in range(N) : 
    k = int(input())
    A = list(map(int, input().split()))
    if X in A : continue
    ok = False
print("YES "if ok else "NO")