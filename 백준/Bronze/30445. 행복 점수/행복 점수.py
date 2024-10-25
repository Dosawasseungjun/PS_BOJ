S = input()
h, k = 0, 0
for s in S :
    h += 1 if (s in "HAPPY") else 0
    k += 1 if (s in "SAD") else 0
if h + k == 0 :
    print("50.00")
else :
    import math
    res = h*100/(h+k) * 100 + 0.5
    res = math.floor(res) / 100
    print("{:.2f}".format(res))