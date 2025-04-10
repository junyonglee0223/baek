#s21736 헌내기는 친구가 필요해

from collections import deque

def is_range(x, y, n, m):
    return 0 <= x < n and 0 <= y < m

def solution_need_friends():
    n, m = map(int, input().split())

    board = [[0] * m for _ in range(n)]
    start_x = -1
    start_y = -1
    for i in range(n):
        line = input()
        for j, ch in enumerate(line):
            if ch == 'O':
                board[i][j] = 0
            elif ch == 'P':
                board[i][j] = 1
            elif ch == 'X':
                board[i][j] = -1
            elif ch == 'I':
                start_x, start_y = i, j
                board[i][j] = 0


    answer = 0
    q = deque()
    q.append((start_x, start_y))

    board[start_x][start_y] = -1

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    while q : 
        cx, cy = q.popleft()

        for d in range(4):
            nx = cx + dx[d]
            ny = cy + dy[d]

            if not is_range(nx, ny, n, m): continue
            if board[nx][ny] < 0 : continue

            if board[nx][ny] == 1:
                answer += 1
            
            board[nx][ny] = -1
            q.append((nx, ny))
        
    if answer == 0:
        print("TT")
    else:
        print(answer)

if __name__ == "__main__":
    solution_need_friends()


# if __name__ == "__main__":
#     T = int(input())
#     while T > 0 :
#         solution_need_friends()
#         T -= 1
