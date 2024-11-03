N = int(input())
A,B,C,D = input(), input(), input(), input()
f = True
r = ""
for i in range(N) :
    if A[i] == C[i] :
        if B[i] != D[i] :
            f = False
        else : 
            r += B[i]
print(r if f else "htg!")