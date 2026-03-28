import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()

stk = []

for c in s : 
    stk.append(c)

    while 1 : 
        if len(stk) >= 2 and stk[-1] == stk[-2] : 
            stk.pop()
            stk.pop()
        elif len(stk) >= 3 and stk[-1] == stk[-3] : 
            stk.pop()
            stk.pop()
            stk.pop()
        else : 
            break
print(''.join(stk) if stk else -1)