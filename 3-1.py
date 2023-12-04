from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def spread_virus2(target_x, target_y, s):
    visited = [[0] * n for _ in range(n)]
    q = deque()
    q.append((target_x, target_y, 0))  
    visited[target_x][target_y] = 1

    min_virus = float('inf') 

    while q:
        x, y, time = q.popleft()
        current_virus = lab[x][y]
        
        if time <= s and current_virus != 0:
            min_virus = min(min_virus, current_virus)

        if time > s:
            break

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and visited[nx][ny] == 0:
                visited[nx][ny] = 1
                q.append((nx, ny, time + 1))

    return min_virus if min_virus != float('inf') else 0  

n, k = map(int, input().split())
lab = [list(map(int, input().split())) for _ in range(n)]
s, target_x, target_y = map(int, input().split())

print(spread_virus2(target_x-1, target_y-1, s))
