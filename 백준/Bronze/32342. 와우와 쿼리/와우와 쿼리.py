for _ in range(int(input())) :
    S = input()
    res = 0
    for i in range(len(S)-2) :
        if S[i:i+3] == "WOW" : res += 1
    print(res)