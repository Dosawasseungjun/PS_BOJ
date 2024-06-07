dp1 = [0 for _ in range(81)]
dp1[1] = 1
dp1[2] = 1
for i in range(3, 81) :
    dp1[i] = dp1[i-1] + dp1[i-2]
dp2 = [0 for _ in range(81)]
dp2[1] = dp1[1] * 4
dp2[2] = dp2[1] + dp1[2] * 2
for i in range(3, 81) :
    dp2[i] = dp2[i-1] + dp1[i] * 2
n = int(input())
print(dp2[n])