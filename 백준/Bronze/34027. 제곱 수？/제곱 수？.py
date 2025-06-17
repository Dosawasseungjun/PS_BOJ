import math
for _ in range(int(input())) : 
    N = int(input())
    x = int(math.sqrt(N))
    print(1 if N == x*x else 0)