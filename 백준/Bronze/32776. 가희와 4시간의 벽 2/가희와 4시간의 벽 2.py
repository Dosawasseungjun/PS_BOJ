a = int(input())
b, c, d =map(int, input().split())

if a <= 240 or a <= b + c + d : 
    print("high speed rail")
else :
    print("flight")