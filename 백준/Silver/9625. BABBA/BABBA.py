k = int(input())
a, b = 1, 0
for i in range(k) :
    pa, pb = a, b
    a = pb
    b = pa + pb 
print(a, b)