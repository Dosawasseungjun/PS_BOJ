while 1 : 
    s = input()
    if s == 'end' : break

    ok = 0
    oc, xc = s.count('O'),s.count('X')
    D = {}
    D['O'], D['X'] = 0, 0
    # 꽉차서 끝난경우
    if  oc == 4 and xc == 5 : 
        ok = 1

    # 세로 확인
    for i in range(3) : 
        if s[i] == s[i+3] == s[i+6] and s[i] != '.' : 
            ok = 1
            D[s[i]] += 1
            
    
    # 가로 확인
    for i in range(3) : 
        if s[i*3] == s[3*i+1] == s[3*i+2] and s[3*i] != '.' :
            ok = 1
            D[s[3*i]] += 1
    
    # 대각선 확인
    if (s[0] == s[4] == s[8] and s[0] != '.') : 
        ok = 1
        D[s[4]] += 1
    if (s[2] == s[4] == s[6] and s[2] != '.') :
        ok = 1
        D[s[4]] += 1
    
    # 개수 안맞음
    if xc - oc > 1 or  xc -oc < 0: 
        ok = 0
    # print(D)
    if D['O'] > 1 or (D['O'] == 1 and D['X'] == 1) or (xc > oc and D['O'] > 0) or (xc == oc and D['X'] > 0):
        ok = 0

    print("valid" if ok else "invalid")
    
    