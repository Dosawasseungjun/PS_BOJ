x, y = map(int, input().split())
a, b, c, d, e = map(int, input().split())
p = a * x**3 // 3 + (b-d) * x**2 // 2 + (c-e) * x
q = a * y**3 // 3 + (b-d) * y**2 // 2 + (c-e) * y
print(q - p)