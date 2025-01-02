S = input()
A, B, C, R = 0, 0, 0, 0
for c in S[::-1] :
    if c == 'A' : 
        if B : 
            B -= 1
            R += 1
    elif c == 'B' : 
        if C : 
            C -= 1
            R += 1
        else : 
            B += 1
    else : 
        C += 1
print(R)