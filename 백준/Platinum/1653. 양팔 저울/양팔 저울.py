from itertools import combinations, permutations
n = int(input())
A = list(map(int,input().split()))
k = int(input())
D = {}
for i in range(1, min(len(A)+1, 6)) :
    for C in combinations(A, i) :
        tmp = [0] * (5 - len(C)) + list(C)
        for P in sorted(set(permutations(tmp, 5))) :
          S = 0
          for j in range(5, 0, -1) : 
             S += j * P[5-j]
          if S in D : D[S].append(list(map(str, P)))
          else : D[S] = [list(map(str, P))]
# print(D)
R = []
for key, val in D.items() : 
   if len(val) < 2 : continue
   for a, b in combinations(val, 2) :
        st1, st2,  = set(), set()
        for aa in a : 
            if aa != '0' : st1.add(aa)
        for bb in b : 
            if bb != '0' : st2.add(bb)

        if st1 & st2 : continue
        else : 
            ra, rb = list(a), list(b)
            ra.reverse()
            rb.reverse()
            p = int(''.join(a + rb))
            q = int(''.join(b + ra))
            R.append(p)
            R.append(q)
R.sort()
if k-1 < len(R) : print(R[k-1])
else : print(R[-1])