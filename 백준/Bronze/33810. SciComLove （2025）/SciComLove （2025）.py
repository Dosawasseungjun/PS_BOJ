S = "SciComLove"
T = input()
R = 0
for idx, c in enumerate(T) :
    if S[idx] != c :  R += 1;
print(R)