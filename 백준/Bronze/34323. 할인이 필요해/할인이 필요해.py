N, M, S = map(int, input().split())
A, B = M*S*100, (M+1)*(S * (100 - N))
R = min(A, B)
print(R // 100)