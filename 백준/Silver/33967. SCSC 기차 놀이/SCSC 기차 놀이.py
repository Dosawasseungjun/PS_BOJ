N = int(input())
S = input()
R = N-1
for i in range(1, N) : 
    if S[i-1] == S[i] == '5' or S[i-1] == S[i] == '2':
        R += 1
    elif S[i-1] == ']' and S[i] == '[' : R -= 1
print(R)