S = input()
N = int(input())
res = 0
for i in range(N) :
    s = input()
    if s[:5] == S[:5] :
        res += 1
print(res)