A = list(map(int, input().split()))
B = list(map(int, input().split()))
X = [13, 7, 5, 3, 3, 2]
a = sum([x * y for x, y in zip(A, X)])
b = sum([x * y for x, y in zip(B, X)])
print("cocjr0208" if a > b+1 else "ekwoo")