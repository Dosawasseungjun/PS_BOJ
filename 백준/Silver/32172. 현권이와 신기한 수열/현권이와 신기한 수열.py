N = int(input())
A = 0
st = set([A])
for i in range(1, N+1) : 
    if A - i < 0 or (A - i in st) : 
        A += i
    else : 
        A -= i
    st.add(A)
print(A)