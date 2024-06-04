S = [
    "G...",
    ".I.T",
    "..S.",
]
N = int(input())
for s in S :
    for i in range(N) :
        for c in s :
            print(c * N, end="")
        print()