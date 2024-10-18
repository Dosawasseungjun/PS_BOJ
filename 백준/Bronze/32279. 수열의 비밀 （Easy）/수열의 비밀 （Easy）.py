n = int(input())
p, q, r, s = map(int, input().split())
a = [int(input())]
i = 1
k = a[i-1]
while 2*i <= n or 2*i+1 <= n : 
    k += p * a[i-1] + q
    a.append(p * a[i-1] + q)
    if 2*i+1 <= n : 
        k += r*a[i-1] + s
        a.append(r*a[i-1] + s)
    i += 1
print(k)