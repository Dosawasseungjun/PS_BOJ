while 1 :    
    args = list(map(int, input().split()))
    if args[0] == 0 : break
    x = 1
    for i in range(1, 2 * args[0] + 1, 2) :
        x *= args[i]
        x -= args[i+1]
    print(x)