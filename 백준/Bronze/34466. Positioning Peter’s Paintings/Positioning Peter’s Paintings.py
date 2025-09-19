a, b, c, d = map(int, input().split())
r = min((a+c+max(b, d)), (b+d+max(a, c)))
print(2*r)