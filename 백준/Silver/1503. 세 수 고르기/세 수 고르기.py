N, M = map(int, input().split())
A = [i for i in range(1, 2001)]
S = list(map(int, input().split())) if M else [0]
B = []
for a in A : 
    if a in S :
        continue
    B.append(a)
res = 10 ** 9
for x in B :
    for y in B : 
        pre = res
        for z in B :
            res = min(res, abs(N - x*y*z))
            if pre < 0 and pre > N - x*y*z :
                break
            else : 
                pre = N - x*y*z
print(res)