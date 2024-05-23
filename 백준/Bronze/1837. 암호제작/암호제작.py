p, k = map(int, input().split())
r = 1
for i in range(2, k) :
    if p % i == 0 : 
        r = i
        break
print("GOOD") if r == 1 else print("BAD", r)