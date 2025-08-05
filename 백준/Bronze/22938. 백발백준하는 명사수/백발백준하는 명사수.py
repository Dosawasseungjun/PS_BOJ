a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
g = (d-a)**2 + (e-b)**2
h = (f+c)**2
print("YES" if g < h else "NO")