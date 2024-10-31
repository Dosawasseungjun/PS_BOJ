N = input()
carry = 0
R = [0 for _ in range(len(N))]
for i in range(len(N)-1, 0, -1) :
    if int(N[i]) + carry >= int('5'):
        carry = 1
        R[i] = '0'
    else :
        carry = 0
        R[i] = '0'
R[0] = str(int(N[0]) + carry)
print(''.join(R))