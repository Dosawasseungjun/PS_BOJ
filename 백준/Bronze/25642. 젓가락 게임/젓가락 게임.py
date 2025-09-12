A, B = map(int, input().split())
c = 0
while A < 5 and B < 5 : 
    if c & 1 :
        A += B 
    else :
        B += A
    c += 1
print("yt" if B >= 5 else "yj")