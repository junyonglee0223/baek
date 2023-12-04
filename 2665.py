
from collections import deque

N = int(input())
#room = [list(map(int, input().split()))for _ in range(N)]

room = []
for _ in range(N):
    row = list(map(int, input().split()))
    room.append(row)
print(room)
#print(room[0][1])

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

tot_room = 0
for i in range(N):
    for j in range(N):
        print(room[i][j])
        if room[i][j] == 0:
            print("!!!!")
            tot_room += 1



print(tot_room)



