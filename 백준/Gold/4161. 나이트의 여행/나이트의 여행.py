while 1 :
    s = input()
    if s == "END" : break
    a, b = map(int, s.split())
    a, b = map(abs, [a, b])
    if a < b : 
        a, b = b, a
    d = max((a + 1) // 2, (a + b + 1) // 3)
    if (d % 2) != ((a + b) % 2):
        d += 1
    if a == 1 and b == 0 : 
        d = 3
    if a == 2 and  b == 2 :
        d = 4
    print(d)