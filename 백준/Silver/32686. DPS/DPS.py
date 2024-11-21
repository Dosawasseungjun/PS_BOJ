N, S, E = map(int, input().split())
D = 0.0
for _ in range(N) :
    t, c, d = map(int, input().split())
    p = (E // (t+c)) * c + E % (t+c) - min(E % (t+c), t)
    q = (S // (t+c)) * c + S % (t+c) - min(S % (t+c), t)
    k = p - q
    D += (d/c) * k
print(D / (E - S))