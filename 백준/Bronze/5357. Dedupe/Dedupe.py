for _ in range(int(input())) : 
    s = input()
    res = s[0]
    for i in range(1, len(s)) :
        if s[i-1] != s[i] :
            res += s[i]
    print(res)