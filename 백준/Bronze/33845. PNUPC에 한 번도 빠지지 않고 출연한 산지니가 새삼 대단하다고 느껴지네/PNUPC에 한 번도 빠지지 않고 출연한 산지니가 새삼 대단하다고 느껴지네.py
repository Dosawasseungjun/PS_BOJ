S = input()
T = input()
R = ""
for c in T : 
    if c in S : continue
    R += c
print(R)