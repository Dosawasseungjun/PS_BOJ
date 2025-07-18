N = int(input())
A = []
for i in range(N) : 
    A.append(int(input()))
B = A[:]
B.sort()
if A[0] == B[0] : 
    print("ez")
elif A[0] == B[-1] :
    print("hard")
else : 
    print("?")