R = 0
for i in range(3) : 
    S = input()
    if S == "Fizz" or S == "Buzz" or S == "FizzBuzz" : continue
    R = int(S) + 3 - i
if R % 3 == 0 and R % 5  == 0 : 
    print("FizzBuzz")
elif R % 3 == 0 :
    print("Fizz")
elif R % 5 == 0 : 
    print("Buzz")
else : 
    print(R)