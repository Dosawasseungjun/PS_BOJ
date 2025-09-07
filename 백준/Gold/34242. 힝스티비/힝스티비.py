S = input()
n = len(S)
res = 0
flag = False
for i in range(2, n) :
    if S[i-2:i+1] == "+^+" : 
        res += 1
    if S[i-2:i+1] == "-^-" :
        res -= 1
        flag = True

for i in range(3, n) :
    if S[i-3:i+1] == "+-^+" or S[i-3:i+1] == "+^-+" or S[i-3:i+1] == "+^^+":
        flag = True
for i in range(4, n) :
    if S[i-4:i+1] == "-^-^-" : 
        flag = False
        res += 2
        break
res += flag
print(res)

"""
+^+^^+
"""