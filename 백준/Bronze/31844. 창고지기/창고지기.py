s = input()
k = ""
for c in s :
    if c != '.' : k += c
if k == "!#@" or k == "@#!" :
    print(abs(s.index('!') - s.index("@")) - 1)
else :
    print(-1)