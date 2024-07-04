N = int(input())
D = [0 for _ in range(N)]
for i in range(N) :
    A, B = map(int, input().split())
    D[i] = A - B
D.sort()
if N & 1 : print(1)
else : print(D[N//2] - D[N//2 - 1] + 1)