N, M = input().split()
print("SN " + N + (chr(int(M)+ord('A')-1) if int(M) <= 26 else chr(ord('a')+(int(M)-27)//26)+chr(ord('a')+(int(M)-27)%26)))