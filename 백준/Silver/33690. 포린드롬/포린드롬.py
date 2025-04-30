N = int(input())
R = 1
for i in range(1, 10) : 
    x = str(i)
    p = x
    while int(p) <= N : 
        R += 1
        p = p + x
print(R)
