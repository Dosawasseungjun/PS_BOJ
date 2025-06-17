A, B, C = map(int, input().split())
res = (A - 2015) * 4 + 1
if 3 <= B <= 5 : res += 1
elif 6 <= B <= 8 : res += 2
elif 9 <= B <= 11 : res += 3
elif B == 12 : res += 4
print(res)
