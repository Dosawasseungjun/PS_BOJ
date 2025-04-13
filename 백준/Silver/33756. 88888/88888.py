arr = [8]
for i in range(18) : 
    arr.append(arr[-1]*10+8)
for _ in range(int(input())) :
    N = int(input())
    k = N
    cnt =0
    for i in range(18, -1, -1) : 
        while k >= arr[i] : 
            k -= arr[i]
            cnt += 1
    print("No" if (k or cnt > 8) else "Yes")