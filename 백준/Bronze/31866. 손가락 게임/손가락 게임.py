A, B = map(int, input().split())
cnt = [1, 0, 2, 0, 0, 5]
if cnt[A] == 0 and cnt[B] == 0 : print("=")
elif cnt[A] == 0 : print("<") 
elif cnt[B] == 0 : print(">") 
else :
    if cnt[A] == 1 :
        if cnt[B] == 1 : print("=")
        elif cnt[B] == 2 :print(">")
        else : print("<")
    elif cnt[A] == 2: 
        if cnt[B] == 1 : print("<")
        elif cnt[B] == 2 :print("=")
        else : print(">")
    else : 
        if cnt[B] == 1 : print(">")
        elif cnt[B] == 2 :print("<")
        else : print("=")