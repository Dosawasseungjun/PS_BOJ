A = input()
B = input()
R1 = ""
flg1 = False
for i in range(len(A)) : 
    if A[i] in "aeiou" and not flg1 :
        flg1 = True
    elif A[i] not in "aeiou" and flg1 : 
        R1 += A[:i]
        break
R2 = ""
flg2 = False
for i in range(len(B)) : 
    if B[i] in "aeiou" and not flg2 :
        flg2 = True
    elif B[i] not in "aeiou" and flg2 : 
        R2 += B[:i]
        break
print(R1 + R2 if R1 != "" and R2 != "" else "no such exercise")