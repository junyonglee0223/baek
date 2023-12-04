

#2606
def dfs(graph, v, visited):
    visited[v] = True
    count = 1  # 웜 바이러스에 걸리는 컴퓨터 수를 세기 위한 변수
    for i in graph[v]:
        if not visited[i]:
            count += dfs(graph, i, visited)
    return count

# 컴퓨터의 수 입력
n = int(input())

# 그래프 초기화
graph = [[] for _ in range(n + 1)]

# 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수 입력
m = int(input())

# 네트워크 정보 입력
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# 방문 여부를 저장하는 리스트 초기화
visited = [False] * (n + 1)

# 1번 컴퓨터부터 시작하여 DFS 실행
result = dfs(graph, 1, visited)

# 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수 출력
print(result - 1)  # 1번 컴퓨터는 제외





#1197
def find_parent(parent, node):
    if parent[node] == node:
        return node
    parent[node] = find_parent(parent, parent[node])
    return parent[node]

def union(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a != b:
        parent[b] = a

# 입력 받기
V, E = map(int, input().split())
edges = []
for _ in range(E):
    A, B, C = map(int, input().split())
    edges.append((C, A, B))

edges.sort()

parent = [i for i in range(V + 1)]

total_weight = 0

for edge in edges:
    weight, A, B = edge
    if find_parent(parent, A) != find_parent(parent, B):
        union(parent, A, B)
        total_weight += weight

# 결과 출력
print(total_weight)







#1707
from collections import deque

def is_bipartite(graph, start, visited):
    colors = [-1] * len(graph)
    queue = deque([start])
    colors[start] = 1
    visited[start] = True

    while queue:
        curr = queue.popleft()
        for neighbor in graph[curr]:
            if colors[neighbor] == -1:  # 아직 방문하지 않은 경우
                colors[neighbor] = 1 - colors[curr]  # 현재 정점과 다른 색으로 칠하기
                visited[neighbor] = True
                queue.append(neighbor)
            elif colors[neighbor] == colors[curr]:  # 이미 칠해진 색이 현재 정점과 같으면 이분 그래프가 아니다.
                return False
    return True

def main():
    K = int(input())
    for _ in range(K):
        V, E = map(int, input().split())
        graph = [[] for _ in range(V + 1)]
        visited = [False] * (V + 1)

        for _ in range(E):
            u, v = map(int, input().split())
            graph[u].append(v)
            graph[v].append(u)

        bipartite = True
        for i in range(1, V + 1):
            if not visited[i]:
                if not is_bipartite(graph, i, visited):
                    bipartite = False
                    break

        if bipartite:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()






#21606

N = int(input())
A = input().strip()

edges = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    v1, v2 = map(int, input().split())
    edges[v1].append(v2)
    edges[v2].append(v1)

indoor = [i for i in range(1, N + 1) if A[i - 1] == '1']

def dfs_class(src, dst):
    visited = [0] * (N + 1)
    visited[src] = 1
    stack = [src]
    cnt = 0

    while stack:
        node = stack.pop()
        if node == dst:
            cnt += 1
        for nxt in edges[node]:
            if not visited[nxt] and (nxt not in indoor or nxt == dst):
                visited[nxt] = 1
                stack.append(nxt)

    return cnt

ans = 0
for i in range(len(indoor)):
    for j in range(len(indoor)):
        if i == j:
            continue
        src = indoor[i]
        dst = indoor[j]
        ans += dfs_class(src, dst)

print(ans)



def dfs(tree, start, end, indoor):
    if start == end:
        return 1

    count = 0
    for neighbor in tree[start]:
        if neighbor not in indoor or neighbor == end:
            count += dfs(tree, neighbor, end, indoor)
    return count

def count_paths(N, A, edges):
    tree = {i: [] for i in range(1, N + 1)}
    for u, v in edges:
        tree[u].append(v)
        tree[v].append(u)

    indoor = [i for i in range(1, N + 1) if A[i-1] == '1']
    
    result = 0
    for i in range(len(indoor)):
        for j in range(i + 1, len(indoor)):
            start, end = indoor[i], indoor[j]
            result += dfs(tree, start, end, set(indoor))

    return result

if __name__ == "__main__":
    N = int(input())
    A = input().strip()
    edges = [tuple(map(int, input().split())) for _ in range(N - 1)]

    print(count_paths(N, A, edges))


import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())

A = input().rstrip()

graph = [[] for _ in range(n+1)]
place = [0] * (n+1)
visited = [0] * (n+1)

for i in range(len(A)):
    if A[i] == '1':
        place[i+1] = 1

for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
def dfs(node):
    res = 0 
    for next_node in graph[node]:
        if place[next_node] == 0:
            if not visited[next_node]:
                visited[next_node] = 1
                res += dfs(next_node)
        else:
            res += 1
    return res

ans = 0
for i in range(1, n+1):
    if place[i] == 0:
        if not visited[i]:
            visited[i] = 1
            res = dfs(i)
            ans += res * (res - 1)
    else:
        for next_node in graph[i]:
            if place[next_node] == 1:
                ans += 1
print(ans)




#14888 
n = int(input())
numbers = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

min_val = float('inf')
max_val = float('-inf')

def dfs(i, res, add, sub, mul, div):
    global max_val, min_val
    if i == n:
        max_val = max(max_val, res)
        min_val = min(min_val, res)
        return
    
    if add:
        dfs(i+1, res+numbers[i], add-1, sub, mul, div)
    if sub:
        dfs(i+1, res-numbers[i], add, sub-1, mul, div)
    if mul:
        dfs(i+1, res*numbers[i], add, sub, mul-1, div)
    if div:
        if res < 0:
            dfs(i+1, -(-res//numbers[i]), add, sub, mul, div-1)
        else:
            dfs(i+1, res//numbers[i], add, sub, mul, div-1)

dfs(1, numbers[0], add, sub, mul, div)
print(max_val)
print(min_val)



#2573
from collections import deque

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def bfs(x, y, visited, iceberg):
    q = deque([(x, y)])
    visited[x][y] = True
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny]:
                if iceberg[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny))

def count_iceberg(iceberg):
    visited = [[False] * M for _ in range(N)]
    count = 0
    for i in range(N):
        for j in range(M):
            if iceberg[i][j] and not visited[i][j]:
                bfs(i, j, visited, iceberg)
                count += 1
    return count

def melt_iceberg(iceberg):
    melted = [[0] * M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if iceberg[i][j]:
                for k in range(4):
                    ni, nj = i + dx[k], j + dy[k]
                    if 0 <= ni < N and 0 <= nj < M and not iceberg[ni][nj]:
                        melted[i][j] += 1
    for i in range(N):
        for j in range(M):
            iceberg[i][j] = max(iceberg[i][j] - melted[i][j], 0)

N, M = map(int, input().split())
iceberg = [list(map(int, input().split())) for _ in range(N)]

years = 0
while True:
    cnt = count_iceberg(iceberg)
    if cnt == 0:
        print(0)
        break
    if cnt >= 2:
        print(years)
        break
    melt_iceberg(iceberg)
    years += 1




#2617
N, M = map(int, input().split())

# 무게 관계를 저장할 2차원 리스트
relation = [[0]*N for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    relation[a-1][b-1] = 1  # a가 b보다 무겁다.

# 플로이드-와샬 알고리즘을 이용해 전이 관계 업데이트
for k in range(N):
    for i in range(N):
        for j in range(N):
            if relation[i][k] == 1 and relation[k][j] == 1:
                relation[i][j] = 1

cnt = 0
for i in range(N):
    num_heavier = sum(relation[i])
    num_lighter = sum([relation[j][i] for j in range(N)])
    if num_heavier >= (N+1) // 2 or num_lighter >= (N+1) // 2:
        cnt += 1

print(cnt)





#1916
import heapq

INF = int(1e9)
N = int(input())
M = int(input())

# 각 도시에 연결된 도로와 비용 정보를 담은 리스트
graph = [[] for _ in range(N + 1)]

# 버스 정보 입력
for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

def dijkstra(start):
    distance = [INF] * (N + 1)
    distance[start] = 0
    q = []
    heapq.heappush(q, (0, start))
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance

start, end = map(int, input().split())
distance = dijkstra(start)
print(distance[end])




#2665 
import sys
import heapq

get_input = sys.stdin.readline

maze_size = int(get_input())
labyrinth = []
for _ in range(maze_size):
    labyrinth.append(list(map(int, get_input().rstrip())))

# Directions for moving up, down, left, right
dir_x = [1, -1, 0, 0]
dir_y = [0, 0, 1, -1]

# Matrix to keep track of visited cells
is_visited = [[False] * maze_size for _ in range(maze_size)]

def shortest_path(x_start, y_start):
    min_heap = []
    heapq.heappush(min_heap, (0, x_start, y_start))

    while min_heap:
        steps, curr_x, curr_y = heapq.heappop(min_heap)
        is_visited[curr_x][curr_y] = True

        # If destination is reached
        if curr_x == (maze_size - 1) and curr_y == (maze_size - 1):
            return steps

        # Check all possible moves
        for i in range(4):
            next_x = curr_x + dir_x[i]
            next_y = curr_y + dir_y[i]

            if (0 <= next_x < maze_size) and (0 <= next_y < maze_size) and not is_visited[next_x][next_y]:
                # Mark as visited
                is_visited[next_x][next_y] = True
                # White cell
                if labyrinth[next_x][next_y] == 1:
                    heapq.heappush(min_heap, (steps, next_x, next_y))
                # Black cell
                else:
                    heapq.heappush(min_heap, (steps + 1, next_x, next_y))

print(shortest_path(0, 0))





#7569
import sys
from collections import deque

m, n, h = map(int, input().split())  # Box dimensions
boxes = []
ripe_queue = deque([])

for i in range(h):
    layer = []
    for j in range(n):
        row = list(map(int, sys.stdin.readline().split()))
        layer.append(row)
        for k in range(m):
            if row[k] == 1:
                ripe_queue.append([i, j, k])
    boxes.append(layer)

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

while ripe_queue:
    x, y, z = ripe_queue.popleft()
    
    for i in range(6):
        nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]
        if 0 <= nx < h and 0 <= ny < n and 0 <= nz < m and boxes[nx][ny][nz] == 0:
            ripe_queue.append([nx, ny, nz])
            boxes[nx][ny][nz] = boxes[x][y][z] + 1

max_days = 0
for layer in boxes:
    for row in layer:
        if 0 in row:
            print(-1)
            exit(0)
        max_days = max(max_days, max(row))
print(max_days - 1)





#2294 
n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

dp = [float('inf')] * (k + 1)
dp[0] = 0

for coin in coins:
    for i in range(coin, k + 1):
        dp[i] = min(dp[i], dp[i - coin] + 1)

if dp[k] == float('inf'):
    print(-1)
else:
    print(dp[k])

#2252








from collections import deque

N, M = map(int, input().split())

indegree = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

def topology_sort():
    result = []
    q = deque()
    
    for i in range(1, N + 1):
        if indegree[i] == 0:
            q.append(i)

    while q:
        now = q.popleft()
        result.append(now)

        for i in graph[now]:
            indegree[i] -= 1
            
            if indegree[i] == 0:
                q.append(i)

    return result

result = topology_sort()
for i in result:
    print(i, end=' ')







#2637
import sys
from collections import deque

get_input = sys.stdin.readline
num_components = int(get_input())

component_relations = [[] for _ in range(num_components + 1)]
requirements = [[0] * (num_components + 1) for _ in range(num_components + 1)]

processing_queue = deque()
indegrees = [0] * (num_components + 1)

for _ in range(int(get_input())):
    base, target, quantity = map(int, get_input().split())
    component_relations[target].append((base, quantity))
    indegrees[base] += 1

for idx in range(1, num_components + 1):
    if indegrees[idx] == 0:
        processing_queue.append(idx)

while processing_queue:
    current_component = processing_queue.popleft()

    for next_component, next_quantity in component_relations[current_component]:
        if requirements[current_component].count(0) == num_components + 1:
            requirements[next_component][current_component] += next_quantity
        else:
            for i in range(1, num_components + 1):
                requirements[next_component][i] += requirements[current_component][i] * next_quantity

        indegrees[next_component] -= 1
        if indegrees[next_component] == 0:
            processing_queue.append(next_component)

for component, amount in enumerate(requirements[num_components]):
    if amount > 0:
        print(component, amount)



#1432
import heapq

n = int(input())

graph = [[] for _ in range(n + 1)]

outdegree = [0] * (n + 1)

result = [0] * (n + 1)

for i in range(1, n + 1):
    connection = list(map(int, input()))
    
    for idx, val in enumerate(connection):
        if val == 1:
            graph[idx + 1].append(i)
            outdegree[i] += 1

def topology_sort(n):
    heap = []

    for i in range(1, n + 1):
        if outdegree[i] == 0:
            heapq.heappush(heap, -i)

    while heap:
        now = -heapq.heappop(heap)
        result[now] = n

        for connected_node in graph[now]:
            outdegree[connected_node] -= 1
            if outdegree[connected_node] == 0:
                heapq.heappush(heap, -connected_node)

        n -= 1

topology_sort(n)

if result.count(0) > 2:
    print(-1)
else:
    print(' '.join(map(str, result[1:])))





#1948 
import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
M = int(input())

time = [0] * (N + 1)
in_degree = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]
bgraph = [[] for _ in range(N + 1)]
cnt = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))
    bgraph[b].append(a)
    in_degree[b] += 1

src, dst = map(int, input().split())

q = deque([])
q.append(src)

while q:
    now = q.popleft()
    for i in graph[now]:
        in_degree[i[1]] -= 1
        if time[i[1]] < time[now] + i[0]:
            time[i[1]] = time[now] + i[0]
            cnt[i[1]] = [now]
        elif time[i[1]] == time[now] + i[0]:
            cnt[i[1]].append(now)

        if in_degree[i[1]] == 0:
            q.append(i[1])

q = deque([dst])
route = set()
while q:
    now = q.popleft()
    for x in cnt[now]:
        if (now, x) not in route:
            route.add((now, x))
            q.append(x)

print(time[dst])
print(len(route))
