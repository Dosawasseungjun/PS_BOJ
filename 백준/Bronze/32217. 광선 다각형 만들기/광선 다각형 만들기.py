N = int(input())
A = list(map(int, input().split()))
print(180 * (N - 1) - 2 * sum(A))