a, b, n, k = map(int, input().split())
x = (k+n-1) // n
print((x+b-1) // b, (x % b if x % b else b))