N = int(input())
S = input()
c = S.count('O')
print("Yes" if c * 2 >= N else "No")