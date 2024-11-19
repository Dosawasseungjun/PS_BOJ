A = int(input())
B = int(input())
C = int(input())
print(str(((A&15)<<8) + ((B&15)<<4) + (C&15)).zfill(4))