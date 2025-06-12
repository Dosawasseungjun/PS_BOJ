N = int(input())
A = list(map(int, input().split()))
print("Bob" if N & 1 else "Alice")
