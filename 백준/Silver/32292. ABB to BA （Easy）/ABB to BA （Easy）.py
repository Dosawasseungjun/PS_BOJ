for _ in range(int(input())) : 
    n = int(input())
    s = input()
    while "ABB" in s : 
        s = s.replace("ABB", "BA")
    print(s)