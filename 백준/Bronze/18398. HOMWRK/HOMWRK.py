for _ in range(int(input())) : 
    n = int(input())
    for i in range(n) :
        a, b = map(int, input().split())
        print(a + b, a * b)