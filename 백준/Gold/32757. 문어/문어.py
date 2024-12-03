n,k = map(int, input().split())
if k >= n : print(0)
elif k & 1 : 
    print(n - (n & 1))
else : 
    print(n)