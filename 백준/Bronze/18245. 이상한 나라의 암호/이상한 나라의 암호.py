import sys
input = sys.stdin.readline
i = 2
while 1 : 
    s = input().strip()
    if s == "Was it a cat I saw?" : 
        break
    res = ''
    for j in range(0, len(s), i) :
        res += s[j]
    print(res)
    i += 1
    