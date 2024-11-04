N, S, f, r = int(input()), input(), True, 0
for i in range(N//2) :
    if S[i] != '?' and S[N-1-i] != '?' and S[i] != S[N-1-i] :
        f = False
    elif S[i] != '?' and S[N-1-i] != '?' and S[i] == S[N-1-i] :
        continue
    elif S[i] == '?' and S[N-1-i] == '?' :
        r += 26
    else :
        r += 1
print(r if f else 0)