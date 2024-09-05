a, b = map(int, input().split())
if a & 1 == 0 : 
    a -= 1
if b & 1 :
    b += 1
print((b-a)//2+1)