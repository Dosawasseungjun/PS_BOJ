N = int(input())
for i in range(N) :
    S = input()
    low, upp, num = 0, 0, 0
    for s in S : 
        if s.isalpha() and s.islower() : low += 1
        if s.isalpha() and s.isupper() : upp += 1
        if s.isdigit() : num += 1
    if upp > low : continue
    if len(S) > 10 : continue
    if len(S) == num : continue
    print(S)
        
