import re
N = int(input())
S = input()
print(sum(map(int, re.split(r'[.\s|\s:\s#]+', S))))