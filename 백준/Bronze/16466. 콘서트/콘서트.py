N = int(input())
A = list(map(int, input().split())) + [1000002]
A.sort()
res, pre = 0, 0
for a in A :
    if pre + 1 == a :
        pre = a
    else : 
        res = pre + 1
print(res)
