while 1:
    try :
        A = input()
        B = input()
        ca = [0 for _ in range(26)]
        cb = [0 for _ in range(26)]
        for a in A : ca[ord(a)-ord('a')] += 1
        for b in B : cb[ord(b)-ord('a')] += 1
        res = ''
        for i in range(26) :
            res += chr(i+ord('a')) * min(ca[i], cb[i])
        print(res)
    except:
        break