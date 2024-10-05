A = list(map(int, input().split()))
a1 = 0
a2 = 3
b1 = sum(A)
b2 = 20
for idx, a in enumerate(A) : 
    if a == 20 : 
        a1 += a + A[(idx-1) % 20] + A[(idx+1) % 20]
if a1 * b2 < a2 * b1 : 
    print("Bob")
elif a1 * b2 == a2 * b1 : 
    print("Tie")
else : 
    print("Alice")