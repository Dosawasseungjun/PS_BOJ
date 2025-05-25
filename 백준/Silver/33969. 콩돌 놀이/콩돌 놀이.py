N, M = map(int, input().split())
G = [input() for _ in range(N)]
c = 0
for g in G :
    c += g.count('x')

def ext_gcd(a, b) :
    if b == 0 :
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1


g, x0, y0 = ext_gcd(11, 9)
mul = c // g
s, c = x0 * mul, y0 *mul
t = (-s + 9 - 1) // 9
s = s + 9*t
c = c - 11*t
print(s, c)
