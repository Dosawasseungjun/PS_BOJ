import math
A, B, C = map(int, input().split())
if C == 0 : 
    print(int(math.sqrt(A + B)))
else :
    print(C * C - max(A, B))