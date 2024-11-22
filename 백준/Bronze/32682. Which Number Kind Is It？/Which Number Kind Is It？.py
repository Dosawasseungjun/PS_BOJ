import sys
input = sys.stdin.readline
st = set(x*x for x in range(1001))
for _ in range(int(input())) : 
    N = int(input())
    R = ""
    if N & 1 : R += 'O'
    if N in st : R += 'S'
    print(R if R else "EMPTY")
