import sys
input = sys.stdin.readline
import math
for i in range(int(input())) : 
    N = int(input())
    k = int(math.sqrt(N))
    if k * k < N : k += 1
    x = (N-1) // k +1
    print(2*(x+k))