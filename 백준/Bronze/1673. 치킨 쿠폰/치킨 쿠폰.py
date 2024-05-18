import sys
input = sys.stdin.readline

while True : 
    try :
        n, k = map(int, input().split())
        res = 0
        ticket = n
        stamp = 0
        while ticket :
            res += ticket
            stamp += ticket
            ticket = stamp // k
            stamp = stamp % k
        print(res)
    except:
        break