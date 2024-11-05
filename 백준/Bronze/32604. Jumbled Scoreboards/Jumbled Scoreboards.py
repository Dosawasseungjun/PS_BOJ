n = int(input())
a, b = 0, 0
f = True
for i in range(n) :
    x, y = map(int, input().split())
    if x >= a and y >= b : 
        a, b = x, y
    else :
        f = False
print("yes" if f else "no")