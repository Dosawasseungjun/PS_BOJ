input()
b, r = 0, 0
for a in input().split() : 
    b += 1 if a == '1' else -1
    r += b
print(r)