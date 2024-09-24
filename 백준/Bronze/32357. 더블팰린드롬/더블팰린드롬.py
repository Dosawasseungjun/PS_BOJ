import sys
input = sys.stdin.readline

N= int(input())
p = 0
for i in range(N) : 
    S = input().rstrip()
    if S == S[::-1] : p += 1
print(p * (p-1))