N, M, K = map(int, input().split())
A = list(map(int, input().split()))
B = [[ele, idx] for idx, ele in enumerate(A)]
B.sort(key= lambda x : x[0])
j = 0
ans = [-1 for _ in range(K)]
for x, idx in B : 
    cnt = 0
    while j < K and M and cnt < x-1 : 
        cnt += 1
        M -= 1
        ans[j] = 0
        j += 1
    if j == K :
        break
    elif cnt == x-1 :
        ans[j] = idx+1
        j += 1
    else : 
        break
while j < K and M :
    ans[j] = 0
    M -= 1
    j += 1
if ans[K-1] != -1 : 
    print(*ans)
else : 
    print(-1)