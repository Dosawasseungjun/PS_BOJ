N, M = map(int, input().split())
st = set()
for i in range(100000) : 
    st.add(i*i)
G = [input() for _ in range(N)]
res = -1
for d1 in range(N+1) :
    for d2 in range(M+1) :
        if d1 == d2 == 0 : continue
        for i in range(N) :
            for j in range(M) :
                s1, s2 = "", ""
                for k in range(10) : 
                    ny = i + d1 * k
                    nx = j + d2 * k 
                    if ny < N and nx < M :
                        s1, s2 = s1 + G[ny][nx], G[ny][nx] + s2
                        c1, c2 = int(s1), int(s2)
                        if c1 in st : res = max(res, c1)
                        if c2 in st : res = max(res, c2)
                    else : 
                        break
                s1, s2 = "", ""
                for k in range(10) : 
                    ny = i + d1 * k
                    nx = j - d2 * k 
                    if 0 <= ny < N and 0 <= nx < M :
                        s1, s2 = s1 + G[ny][nx], G[ny][nx] + s2
                        c1, c2 = int(s1), int(s2)
                        if c1 in st : res = max(res, c1)
                        if c2 in st : res = max(res, c2)
                    else : 
                        break
                        

print(res)