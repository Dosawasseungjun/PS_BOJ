N = int(input())
S = input()
while 1 :
    p = S.find('PS4')
    q = S.find('PS5')

    if p == -1 and q == -1 : 
        break

    if p != -1 :
        S = S.replace('PS4', 'PS')
    if q != -1 : 
        S = S.replace('PS5' , 'PS')
print(S)