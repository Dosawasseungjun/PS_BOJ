N, S = map(int, input().split())
a = list(map(int, input().split()))
res = 0
def knap(n, s, arr) : 
    global res
    if n == N : 
        if S == s : res += 1
        return
    knap(n+1, s, arr)
    knap(n+1, s + arr[n], arr)
knap(0, 0, a)
if S == 0 : res -= 1
print(res)