N, S = input().split()
s = ""
k = 0
for c in S  :
    if c in s : k += 1
    else : s += c
s += str(k + 4)
s = str(int(1906) + int(N)) + s
res = 'smupc_' + s[::-1]
print(res)