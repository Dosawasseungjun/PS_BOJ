import sys
input = sys.stdin.readline

n,k = map(int, input().split())             # n x n chessboard, numbers of Dabbaba 

dbb_arr = []
after_move = set()

for i in range(k) :
    dbb_arr.append(list(map(int,input().split())))     # 2-dimension array managing cordinates
    after_move.add(tuple(dbb_arr[-1]))

for i in range(k) :
    for j in range(4) :
        after_x = dbb_arr[i][0]
        after_y = dbb_arr[i][1]
        if j == 0 :                     
            after_y = dbb_arr[i][1] + 2         # Up
        elif j == 1 :
            after_x = dbb_arr[i][0] + 2         # Right
        elif j == 2 :
            after_y = dbb_arr[i][1] - 2         # Down
        else :
            after_x = dbb_arr[i][0] -2          # Left
        if ((after_x,after_y) in after_move) or (after_x < 1 or after_y < 1) or (after_x > n or after_y > n) :
            continue
        after_move.add((after_x,after_y))
        # movable_cord.append([after_x,after_y])

print(len(after_move) - k)
# dup_deleted =list(set(map(tuple,movable_cord)))
# print(len(dup_deleted))


    