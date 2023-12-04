# in c++ 
# ctrl + k + u
# ctrl + k + c 

# in python
# ctrl + /





# n = int(input())
# scale = list(map(int, input().split()))
# scale.sort()
# #print(scale)    #test
# tot_weight = sum(scale)
# #print(tot_weight)

# weight = [[i] for i in range(tot_weight)]
# for i in range(n):
    
#     for j in range(tot_weight):
#         rest = weight[j] - scale[i]
#         if rest > 0:
#             weight[j] -= scale[i]
    
#     idx = i+1
#     for j in range(0, i+1):
#         if weight[j] > 0:
#             idx = j
#             break 
 





# n, k = map(int, input().split())
# tmp = list(map(int, input().split()))

# cnt = 0
# is_in = [0] * (k + 1)
# tap = []

# for idx, item in enumerate(tmp):
#     if is_in[item]:
#         continue
    
#     if len(tap) < n:
#         tap.append(item)
#         is_in[item] = 1
#         continue
#     remove_idx = -1
#     last_use = -1
#     for i in tap:
#         if i not in tmp[idx+1:]:  
#             remove_idx = i
#             break
#         else:
#             if last_use < tmp[idx+1:].index(i):  
#                 last_use = tmp[idx+1:].index(i)
#                 remove_idx = i

#     tap.remove(remove_idx)
#     is_in[remove_idx] = 0
#     tap.append(item)
#     is_in[item] = 1
#     cnt += 1

# print(cnt)





# n, k = map(int, input().split())

# is_cnt = [0] * (k + 1)
# tmp_list = list(map(int, input().split()))
# tap = []
# cnt = 0
# #print(tmp_list)         #test
# for idx in range(len(tmp_list)):
#     i = tmp_list[idx]
#     #print(i)
#     if is_cnt[i] == 1:
#         continue
#     if len(tap) < n:
#         is_cnt[i] = 1
#         tap.append(i)
#         continue

#     last_cnt = -1
#     remove_idx = -1
#     for j in tap:
#         if j not in tmp_list[idx+1:]:
#             remove_idx = j
#             break
#         else:
#             tmp_idx = tmp_list[idx+1:].index(j)
#             if last_cnt < tmp_idx:
#                 last_cnt = tmp_idx
#                 remove_idx = j
#     tap.remove(remove_idx)
#     is_cnt[remove_idx] = 0

#     tap.append(i)
#     is_cnt[i] = 1
#     cnt += 1

# print(cnt)





#print(use_cnt)





# vkdlTJs 
# xptmxm
# ahrl rmaks rkfk

# N, C = map(int, input().split())
# M = int(input())
# boxes = [list(map(int, input().split())) for _ in range(M)]

# boxes.sort(key=lambda x: (x[1], x[0]))

# delivered = [C] * (N + 1)

# total_boxes = 0

# for send, receive, num_boxes in boxes:
#     min_capacity = min(delivered[send:receive])
#     boxes_to_deliver = min(num_boxes, min_capacity)
    
#     for i in range(send, receive):
#         delivered[i] -= boxes_to_deliver
    
#     total_boxes += boxes_to_deliver

# print(total_boxes)


# #8980 deliver -success
# N, C = map(int, input().split())
# M = int(input())

# package = []
# for _ in range(M):
#     s, e, w = map(int, input().split())
#     package.append([s-1, e-1, w])
# package.sort(key = lambda x: (x[1], x[0]))


# deliver = [C] * (N+1)
# tot_box = 0

# for i in package:
#     s, e, w = i[0], i[1], i[2]

#     check_rest = 10001
#     for j in range(s, e):
#         check_rest = min(check_rest, deliver[j])
    
#     check_rest = min(check_rest, w)
#     for j in range(s, e):
#         deliver[j] -= check_rest
#     tot_box += check_rest
# print(tot_box)
    


# N = int(input())
# board = []
# for _ in range(N):
#     str_tmp = list(map(str, input()))
#     tmp = []
#     for i in str_tmp:
#         if i == 'H':
#             tmp.append(0)
#         elif i == 'T':
#             tmp.append(1)
#     board.append(tmp)

# #print(board)        #test

# checkptn = N//2
# row = [0] * N
# row_sort = []
# for i in range(N):
#     row[i] = sum(board[i])
#     if row[i] > checkptn:
#         row_sort.append([i, row[i]])
# row_sort.sort(key = lambda x:x[1])
# for i in row_sort:
#     idx, c = i[0], i[1]
#     for j in range(N):
#         board[idx][j] = (board[idx][j] + 1)%2

# print(board)        #test

# col = [0] * N
# col_sort = []
# for i in range(N):
#     col[i] = sum(board[x][i] for x in range(N))
#     if col[i] > checkptn:
#         col_sort.append([i], col[i])
# col_sort.sort(key = lambda x:x[1])
# for i in col_sort:
#     idx, c = i[0], i[1]
#     for j in range(N):
#         board[j][idx] = (board[j][idx] + 1)%2


# print(board)        #test




# in c++ 
# ctrl + k + u
# ctrl + k + c 

# in python
# ctrl + /





# n = int(input())
# scale = list(map(int, input().split()))
# scale.sort()
# #print(scale)    #test
# tot_weight = sum(scale)
# #print(tot_weight)

# weight = [[i] for i in range(tot_weight)]
# for i in range(n):
    
#     for j in range(tot_weight):
#         rest = weight[j] - scale[i]
#         if rest > 0:
#             weight[j] -= scale[i]
    
#     idx = i+1
#     for j in range(0, i+1):
#         if weight[j] > 0:
#             idx = j
#             break 
 





# n, k = map(int, input().split())
# tmp = list(map(int, input().split()))

# cnt = 0
# is_in = [0] * (k + 1)
# tap = []

# for idx, item in enumerate(tmp):
#     if is_in[item]:
#         continue
    
#     if len(tap) < n:
#         tap.append(item)
#         is_in[item] = 1
#         continue
#     remove_idx = -1
#     last_use = -1
#     for i in tap:
#         if i not in tmp[idx+1:]:  
#             remove_idx = i
#             break
#         else:
#             if last_use < tmp[idx+1:].index(i):  
#                 last_use = tmp[idx+1:].index(i)
#                 remove_idx = i

#     tap.remove(remove_idx)
#     is_in[remove_idx] = 0
#     tap.append(item)
#     is_in[item] = 1
#     cnt += 1

# print(cnt)





# n, k = map(int, input().split())

# is_cnt = [0] * (k + 1)
# tmp_list = list(map(int, input().split()))
# tap = []
# cnt = 0
# #print(tmp_list)         #test
# for idx in range(len(tmp_list)):
#     i = tmp_list[idx]
#     #print(i)
#     if is_cnt[i] == 1:
#         continue
#     if len(tap) < n:
#         is_cnt[i] = 1
#         tap.append(i)
#         continue

#     last_cnt = -1
#     remove_idx = -1
#     for j in tap:
#         if j not in tmp_list[idx+1:]:
#             remove_idx = j
#             break
#         else:
#             tmp_idx = tmp_list[idx+1:].index(j)
#             if last_cnt < tmp_idx:
#                 last_cnt = tmp_idx
#                 remove_idx = j
#     tap.remove(remove_idx)
#     is_cnt[remove_idx] = 0

#     tap.append(i)
#     is_cnt[i] = 1
#     cnt += 1

# print(cnt)





#print(use_cnt)





# vkdlTJs 
# xptmxm
# ahrl rmaks rkfk

# N, C = map(int, input().split())
# M = int(input())
# boxes = [list(map(int, input().split())) for _ in range(M)]

# boxes.sort(key=lambda x: (x[1], x[0]))

# delivered = [C] * (N + 1)

# total_boxes = 0

# for send, receive, num_boxes in boxes:
#     min_capacity = min(delivered[send:receive])
#     boxes_to_deliver = min(num_boxes, min_capacity)
    
#     for i in range(send, receive):
#         delivered[i] -= boxes_to_deliver
    
#     total_boxes += boxes_to_deliver

# print(total_boxes)


# #8980 deliver -success
# N, C = map(int, input().split())
# M = int(input())

# package = []
# for _ in range(M):
#     s, e, w = map(int, input().split())
#     package.append([s-1, e-1, w])
# package.sort(key = lambda x: (x[1], x[0]))


# deliver = [C] * (N+1)
# tot_box = 0

# for i in package:
#     s, e, w = i[0], i[1], i[2]

#     check_rest = 10001
#     for j in range(s, e):
#         check_rest = min(check_rest, deliver[j])
    
#     check_rest = min(check_rest, w)
#     for j in range(s, e):
#         deliver[j] -= check_rest
#     tot_box += check_rest
# print(tot_box)
    

# def flip_coins(board):
#     N = len(board)
#     min_flips = float('inf')

#     # 모든 행과 열의 뒤집기 조합에 대해 반복
#     for mask in range(1 << N):
#         total_flips = 0
#         new_board = [row[:] for row in board]  # 보드의 사본을 생성

#         # 뒤집기 마스크에 따라 행을 뒤집음
#         for i in range(N):
#             if mask & (1 << i):
#                 # i번째 행의 모든 동전을 뒤집음
#                 for j in range(N):
#                     new_board[i][j] = 'T' if new_board[i][j] == 'H' else 'H'
        
#         # 열의 뒤집기 필요성 확인
#         for j in range(N):
#             heads = sum(new_board[i][j] == 'H' for i in range(N))
#             # 뒤집힌 앞면의 개수가 더 많으면, 열 전체를 뒤집는 것이 이득
#             if heads > N / 2:
#                 total_flips += heads  # 뒤집히는 동전 수를 추가
#             else:
#                 total_flips += N - heads  # 뒤집히지 않는 동전 수를 추가
        
#         # 최소 뒤집기 횟수 갱신
#         min_flips = min(min_flips, total_flips)
    
#     return min_flips

# # 입력 예시
# N = 3
# board = [
#     ['H', 'T', 'H'],
#     ['T', 'H', 'T'],
#     ['H', 'H', 'H']
# ]

# # 출력
# print(flip_coins(board))




# N = int(input())
# board = []
# for _ in range(N):
#     str_tmp = list(map(str, input()))
#     tmp = []
#     for i in str_tmp:
#         if i == 'H':
#             tmp.append(0)
#         elif i == 'T':
#             tmp.append(1)
#     board.append(tmp)

# print(board)        #test


# def dfs_coin(board, visited):
#     cnt = float('inf')
#     for i in range(2*N):
#         if visited & (1 << i) == 0:
#             if i >= N:
#                 for j in range(N):
#                     board[j][i-N] = (board[j][i-N] + 1)%2
#                     cnt = min(cnt, sum(board))
#                     dfs_coin(board, visited | (1 << j))
#                     board[j][i-N] = (board[j][i-N] + 1)%2
#             else:
#                 for j in range(N):
#                     board[i-N][j] = (board[i-N][j] + 1)%2
#                     cnt = min(cnt, sum(board))
#                     dfs_coin(board, visited | (1 << j))
#                     board[i-N][j] = (board[i-N][j] + 1)%2
#     return cnt

# ans = dfs_coin(board, 0)
# print(ans)




# N = int(input())
# board = []
# for _ in range(N):
#     row_state = input().strip()
#     board.append([0 if state == 'H' else 1 for state in row_state])

# min_tails = float('inf')

# for row_flips in range(1 << N):
#     flipped_board = [[cell for cell in row] for row in board]
#     for row in range(N):
#         if row_flips & (1 << row):
#             flipped_board[row] = [1 - cell for cell in flipped_board[row]]

#     for col in range(N):
#         tails_in_col = sum(flipped_board[row][col] for row in range(N))
#         if tails_in_col > N / 2:
#             for row in range(N):
#                 flipped_board[row][col] = 1 - flipped_board[row][col]

#     tails_count = sum(cell for row in flipped_board for cell in row)
#     min_tails = min(min_tails, tails_count)

# print(min_tails)

# T, A, S, B = map(int, input().split())
# nums = list(map(int, input().split()))

# nums_cnt = [0] * (T+1)
# for num in nums:
#     nums_cnt[num] += 1

# dp = [[0] * (A+1) for _ in range(T+1)]
# dp[0][0] = 1

# for i in range(1, T+1):
#     for j in range(A+1):
#         dp[i][j] = dp[i-1][j]  
#         if j >= 1:
#             dp[i][j] += dp[i][j-1]  
#         if j > nums_cnt[i]:
#             dp[i][j] -= dp[i-1][j-nums_cnt[i]-1]  
#         dp[i][j] %= 1000000

# result = sum(dp[T][S:B+1]) % 1000000
# print(result)






# N = int(input())
# bars = list(map(int, input().split()))
# bars.sort(reverse=True)

# max_ele = sum(bars)
# dp = [[] for _ in range(max_ele + 1)]

# for i in range(1 << N):
#     subset_sum = 0
#     for j in range(N):
#         if i & (1 << j):
#             subset_sum += bars[j]
#     dp[subset_sum].append(i)

# max_area = -1

# for length in range(max_ele + 1):
#     for bitmask1 in dp[length]:
#         for other in range(length, max_ele + 1 - length):
#             for bitmask2 in dp[other]:
#                 if bitmask1 & bitmask2 == 0:
#                     area = length * other
#                     print(length, other, area)
#                     #print("\n")                 #test
#                     max_area = max(max_area, area)

# print(max_area)



# N = int(input())
# bars = list(map(int, input().split()))

# max_length = sum(bars)
# dp = [[] for _ in range(max_length + 1)]

# for i in range(1 << N):
#     subset_sum = 0
#     for j in range(N):
#         if i & (1 << j):
#             subset_sum += bars[j]
#     dp[subset_sum].append(i)

# max_area = -1

# for length in range(1, max_length + 1):
#     for bitmask1 in dp[length]:
#         for bitmask2 in dp[length]:
#             if bitmask1 != bitmask2 and not (bitmask1 & bitmask2):
#                 for other in range(length, max_length + 1 - length):
#                     for bitmask3 in dp[other]:
#                         for bitmask4 in dp[other]:
#                             if bitmask3 != bitmask4 and not (bitmask3 & bitmask4):
#                                 if not (bitmask1 & bitmask3) and not (bitmask1 & bitmask4) and not (bitmask2 & bitmask3) and not (bitmask2 & bitmask4):
#                                     area = length * other
#                                     max_area = max(max_area, area)

# print(max_area)




# N = int(input())
# bars = list(map(int, input().split()))

# max_length = sum(bars)
# dp = [[] for _ in range(max_length + 1)]

# # 막대의 부분집합에 대한 합과 비트마스크를 dp에 저장합니다.
# for i in range(1 << N):
#     subset_sum = 0
#     for j in range(N):
#         if i & (1 << j):
#             subset_sum += bars[j]
#     dp[subset_sum].append(i)

# max_area = -1  # 가능한 최대 넓이를 저장합니다.

# # 모든 가능한 길이 조합에 대해 직사각형의 넓이를 계산합니다.
# for length in range(max_length + 1):
#     for bitmask1 in dp[length]:
#         combined = bitmask1
#         for other in range(length, max_length + 1 - length):
#             for bitmask2 in dp[other]:
#                 if not (combined & bitmask2):
#                     area = length * other
#                     max_area = max(max_area, area)
#                     combined |= bitmask2  # 현재 조합에 bitmask2를 추가합니다.

# print(max_area)









# class TreeNode:
#     def __init__(self, value):
#         self.value = value
#         self.left = None
#         self.right = None

#     def insert(self, value):
#         if value < self.value:
#             if self.left is None:
#                 self.left = TreeNode(value)
#             else:
#                 self.left.insert(value)
#         else:
#             if self.right is None:
#                 self.right = TreeNode(value)
#             else:
#                 self.right.insert(value)

# def tree_shape(root):
#     if root is None:
#         return 'null'
#     return f'({tree_shape(root.left)}, {tree_shape(root.right)})'

# def count_unique_tree_shapes(prototypes):
#     shapes = set()
#     for proto in prototypes:
#         root = TreeNode(proto[0])
#         for value in proto[1:]:
#             root.insert(value)
#         shapes.add(tree_shape(root))
#     return len(shapes)

# n, k = map(int, input().split())
# prototypes = [list(map(int, input().split())) for _ in range(n)]

# print(count_unique_tree_shapes(prototypes))



# class TreeNode:
#     def __init__(self, value):
#         self.value = value
#         self.left = None
#         self.right = None
    
#     def insert(self, value):
#         if value < self.value:
#             self = self.left
#         elif value > self.value:
#             self = self.right
        



# N = int(input())
# ret = 0

# pos = []
# neg = []
# flag = 1
# for _ in range(N):
#     e = int(input())
#     if e > 0:
#         pos.append(e)
#     elif e < 0:
#         neg.append(e)
#     else:
#         flag = 0
# pos.sort(reverse=True)
# for i in range(0, len(pos) - 1, 2):
#     ret += (pos[i] * pos[i+1])

# if len(pos) % 2 != 0:
#     ret += pos[-1]


# neg.sort()
# for i in range(0, len(neg) - 1, 2):
#     ret += (neg[i] * neg[i+1])

# if len(neg)%2 != 0:
#     ret += flag * neg[-1]


# print(ret)





# N, M, P = map(int, input().split())
# MOD = 1000000007
# dp = [0] * (P+1)
# dp[0] = 1

# for i in range(1, M):
#     dp[i] = dp[i-1] * (N - i + 1)
#     dp[i] %= MOD

# for i in range(M+1, P+1):
#     dp[i] = dp[i-1] * (N-M+1)
#     dp[i] %= MOD

# print(dp[P+1])

# for i in range(1, P+1):
#     for cnt in range(0, N):
#         if cnt > i:
#             continue
        
#         dp[i][cnt] = (dp[i-1][cnt-1] * (N-cnt+1) + dp[i-1][cnt]*(cnt))%MOD




# """
# dp[i][cnt] = dp[i-1][cnt-1] * (N-cnt+1) + dp[i-1][cnt]*(cnt)

# """

# N, M, P = map(int, input().split())
# MOD = 1000000007
# dp = [[0 for _ in range(N+1)] for _ in range(P+1)]

# dp[0][0] = 1
# for i in range(1, P+1):
#     for cnt in range(1, N+1):
#         if cnt > i:
#             continue
#         if cnt > 0:
#             dp[i][cnt] += dp[i-1][cnt-1] * (N-cnt+1)
#         dp[i][cnt] += dp[i-1][cnt] * cnt
#         dp[i][cnt] %= MOD

# print(dp[P][M])



# N = int(input())

# team = [[0]*(N) for _ in range(N)]
# for i in range(N):
#     row = list(map(int, input().split()))
#     for j in range(N):
#         team[i][j] = row[j]

# ret = float('inf')
# def starlink(idx, lisA, lisB, sub):
#     if idx == N:
#         ret = min(ret, abs(sub))
    
#     tmpA = 0
#     for i in range(len(lisA)):
#         tmpA += (team[lisA[i]][idx] + team[idx][lisA[i]])
#     nlisA = lisA
#     nlisA.append(idx)
#     starlink(idx+1, nlisA, lisB, sub + tmpA)

#     tmpB = 0
#     for i in range(len(lisB)):
#         tmpB += (team[lisB[i]][idx] + team[idx][lisB[i]])
#     nlisB = lisB
#     nlisB.append(idx)
#     starlink(idx+1, lisA, nlisB, sub - tmpB)

# starlink(0, [], [], 0)
# print(ret)




# #카카오 22년인턴쉽 3

# import sys
# input = sys.stdin.readline

# def solution(alp, cop, problems):
#     need_alp_req = 0
#     need_cop_req = 0
#     for i in range(len(problems)):
#         if need_alp_req < problems[i][0]:
#             need_alp_req = problems[i][0]
#         if need_cop_req < problems[i][1]:
#             need_cop_req = problems[i][1]

#     dp = [[0] * (need_alp_req+1) for _ in range(need_cop_req+ 1)]
#     for i in range(cop,need_cop_req+1):
#         for j in range(alp,need_alp_req+1):
#             if i == alp and j == cop:
#                 dp[i][j] = 0
#             elif i != alp and j != cop:
#                 dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1)
#             elif j == cop:
#                 dp[i][j] = dp[i-1][j] + 1
#             elif i == alp:
#                 dp[i][j] = dp[i][j-1] + 1

#             for k in range(len(problems)):
#                 if i - problems[k][3] >= problems[k][1] and j - problems[k][2] >= problems[k][0]: # 코딩력, 알고력 둘다 문제보다 높은 경우
#                     dp[i][j] = min( dp[i][j], dp[i-problems[k][3]][j-problems[k][2]] + problems[k][4])


# #test
#     for i in range(need_cop_req +1 ):
#         for j in range(need_alp_req + 1):
#             print(dp[i][j], end = ' ')
#         print()

#     return dp[need_cop_req][need_alp_req]

# print(solution(0,0,[[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]))




# import heapq

# def solution(alp, cop, problems):
#     q = []
#     heapq.heappush(q,[0,alp,cop]) 
#     need_alp = 0
#     need_cop = 0
#     for problem in problems:
#         if need_alp < problem[0]:
#             need_alp = problem[0]

#         if need_cop < problem[1]:
#             need_cop = problem[1]
#     visited = {}
    
    
#     while True:
#         cur_cost, cur_alp, cur_cop = heapq.heappop(q)
#         if cur_alp >= need_alp and cur_cop >= need_cop:
#             return cur_cost
#         if (cur_alp, cur_cop) in visited:
#             continue
#         visited[(cur_alp, cur_cop)] = True
#         heapq.heappush(q,[cur_cost+1,min(cur_alp+1, need_alp),cur_cop])
#         heapq.heappush(q,[cur_cost+1,cur_alp,min(cur_cop+1, need_cop)])

#         for problem in problems:
#             alp_req, cop_req, alp_rwd, cop_rwd , cost = problem
#             if cur_alp >= alp_req and cur_cop >= cop_req:
#                 new_alp = min(cur_alp + alp_rwd, need_alp)
#                 new_cop = min(cur_cop + cop_rwd, need_cop)
#                 heapq.heappush(q,[cur_cost+cost,new_alp,new_cop])




# # #카카오 22년인턴쉽 4
# import heapq

# max_distance = 100000001

# def dijkstra(graph, start, summits_set):
#     distances = {node: max_distance for node in graph}
#     distances[start] = 0
#     queue = [(0, start)]
    
#     while queue:
#         current_distance, current_node = heapq.heappop(queue)
#         if current_distance > distances[current_node]:
#             continue
#         if current_node in summits_set:
#             continue

#         for next_node, weight in graph[current_node]:
#             distance = max(current_distance, weight)
#             if distance < distances[next_node]:
#                 distances[next_node] = distance
#                 heapq.heappush(queue, (distance, next_node))
    
#     return distances


# def solution(n, paths, gates, summits):
#     graph = {i: [] for i in range(1, n + 1)}
#     for path in paths:
#         i, j, w = path
#         graph[i].append((j, w))
#         graph[j].append((i, w))
#     for gate in gates:
#         graph[0].append((gate, 0))
    
#     summits_set = set(summits)
#     best_summit, min_intensity = 0, max_distance

#     distances = dijkstra(graph, 0, summits_set)
#     for summit in summits:
#         if distances[summit] < min_intensity:
#             min_intensity = distances[summit]
#             best_summit = summit
#         elif distances[summit] == min_intensity and summit < best_summit:
#             best_summit = summit


#     return [best_summit, min_intensity]
    

# #카카오 인턴쉽 2022 5 - fail
# def solution(rc, operations):
#     r = len(rc)
#     c = len(rc[0])

#     for op in operations:
#         if op == "Rotate":
#             temp_top_right = rc[0][c-1]
#             temp_bottom_right = rc[r-1][c-1]
#             temp_bottom_left = rc[r-1][0]
#             temp_top_left = rc[0][0]

#             for i in range(c-2, 0, -1):
#                 rc[0][i+1] = rc[0][i]
#             rc[0][1] = temp_top_left

#             for i in range(r-2, 0, -1):
#                 rc[i+1][c-1] = rc[i][c-1]
#             rc[1][c-1] = temp_top_right

#             for i in range(1, c-1):
#                 rc[r-1][i-1] = rc[r-1][i]
#             rc[r-1][c-2] = temp_bottom_right

#             for i in range(1, r-1):
#                 rc[i-1][0] = rc[i][0]
#             rc[r-2][0] = temp_bottom_left

#         elif op == "ShiftRow":
#             tmp_row = rc[-1]
#             for i in range(r-1, 0, -1):
#                 rc[i] = rc[i-1]
#             rc[0] = tmp_row

#     return rc

#ver2
def solution(rc, operations):
    r = len(rc)
    c = len(rc[0])

    for op in operations:
        if op == "Rotate":
            top = rc[0][1:-1]
            right = [row[-1] for row in rc[1:-1]]
            bottom = rc[-1][1:-1]
            left = [row[0] for row in rc[1:-1]]

            #print(top, right, bottom, left)
            rotated_top = [rc[0][0]] + top
            rotated_right = [rc[0][-1]] + right
            rotated_bottom = bottom + [rc[-1][-1]]
            rotated_left = left + [rc[-1][0]]
            #print(rotated_top, rotated_right, rotated_bottom, rotated_left)

            rc[0] = [rotated_left[0]] + rotated_top
            for i in range(1, len(rc) - 1):
                rc[i] = [rotated_left[i]] + rc[i][1:-1] + [rotated_right[i-1]]
            rc[-1] = rotated_bottom + [rotated_right[-1]]
            # print(rc)           #test
            # print("rotate\n")   

        elif op == "ShiftRow":
            tmp_row = rc[-1]
            for i in range(r-1, 0, -1):
                rc[i] = rc[i-1]
            rc[0] = tmp_row
            # print(rc)           #test
            # print("shift\n")

    return rc

#ver3
def solution(rc, operations):
    r = len(rc)
    c = len(rc[0])
    real_rc = [row[:] for row in rc]  # 깊은 복사
    idx_rc = [[(i, j) for j in range(c)] for i in range(r)]

    for op in operations:
        if op == "Rotate":
            top = idx_rc[0][1:-1]
            right = [row[-1] for row in idx_rc[1:-1]]
            bottom = idx_rc[-1][1:-1]
            left = [row[0] for row in idx_rc[1:-1]]

            rotated_top = [idx_rc[0][0]] + top
            rotated_right = [idx_rc[0][-1]] + right
            rotated_bottom = bottom + [idx_rc[-1][-1]]
            rotated_left = left + [idx_rc[-1][0]]

            idx_rc[0] = [rotated_left[0]] + rotated_top
            for i in range(1, r - 1):
                idx_rc[i] = [rotated_left[i]] + idx_rc[i][1:-1] + [rotated_right[i-1]]
            idx_rc[-1] = rotated_bottom + [rotated_right[-1]]

        elif op == "ShiftRow":
            tmp_row = idx_rc[-1]
            for i in range(r-1, 0, -1):
                idx_rc[i] = idx_rc[i-1]
            idx_rc[0] = tmp_row

    ret_rc = [[0]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            x, y = idx_rc[i][j]
            ret_rc[i][j] = real_rc[x][y]

    return ret_rc


#카카오 2017 안티 세포 - fail
# def count_combinations(b):
#     mod = 10**9 + 7
#     n = len(b)

#     dp = [0] * (n + 1)
#     dp[0] = 1  

#     sum_b = [0] * (n + 1)
#     for i in range(1, n + 1):
#         sum_b[i] = sum_b[i - 1] + b[i - 1]

#     for i in range(1, n + 1):
#         dp[i] = dp[i - 1] 
#         for j in range(i - 1, 0, -1):
#             if sum_b[i] - sum_b[j] == sum_b[j] - sum_b[j - 1]:
#                 dp[i] = (dp[i] + dp[j - 1]) % mod
#             else:
#                 break

#     return dp[n]

# def solution(a, s):
#     answer = []
#     start = 0
#     for length in s:
#         b = a[start:start + length]
#         start += length
#         answer.append(count_combinations(b))
#     return answer




#2021 카카오 미로탈출

import heapq

def solution(n, start, end, roads, traps):
    answer = 0

    ex_roads = [[]for _ in range(2*n+1)]
    for i in roads:
        s, d, r = i
        ex_roads[2*s-1].append([2*d-1, r])
        if d in traps:
            ex_roads[2*d-2].append([2*s-1, r])

    print(ex_roads)


    visited = [0] * (n+1)
    pq = [0, start]
    visited[start] = 1
    distance = [3001] * (n+1)

    while pq:
        now, now_cost = heapq.pop(pq)
        for i in ex_roads[2*now-1]:
            nxt, nxt_c = i[0], i[1]
            if visited[(nxt+1)//2]:
                visited[(nxt+1)//2] = 0
                nxt -= 1
            
            new_cost = now_cost + nxt_c
            





    return answer

import heapq

def solution(n, start, end, roads, traps):
    trap_dict = {trap: i for i, trap in enumerate(traps)}
    ex_roads = [[] for _ in range(n + 1)]
    for s, d, r in roads:
        ex_roads[s].append((d, r, d in traps))
        ex_roads[d].append((s, r, s in traps))

    pq = [(0, start, 0)]  # (누적 시간, 현재 위치, 함정 상태)
    visited = set()

    while pq:
        now_time, now_pos, trap_state = heapq.heappop(pq)
        if now_pos == end:
            return now_time

        if (now_pos, trap_state) in visited:
            continue
        visited.add((now_pos, trap_state))

        for next_pos, time, is_trap in ex_roads[now_pos]:
            next_trap_state = trap_state
            if is_trap and trap_dict[next_pos] >= 0:
                next_trap_state ^= (1 << trap_dict[next_pos])

            reverse_road = False
            if now_pos in trap_dict and trap_dict[now_pos] >= 0:
                reverse_road ^= bool(trap_state & (1 << trap_dict[now_pos]))
            if next_pos in trap_dict and trap_dict[next_pos] >= 0:
                reverse_road ^= bool(trap_state & (1 << trap_dict[next_pos]))

            if reverse_road:
                continue

            heapq.heappush(pq, (now_time + time, next_pos, next_trap_state))

    return 30001




n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)
rev_a = a
a.sort()

mid = n//2
mer_a = []
for i in range(mid+1):
    mer_a.append(a[i])
    mer_a.append(rev_a[i])
print(mer_a)





def solution(k, room_number):
    answer = []
    rooms = {}
    
    for room in room_number:
        i = room
        visited = [i]
        while i in rooms:
            i = rooms[i]
            visited.append(i)
        for j in visited:
            room[j] = i
         
        

    
    return answer



def solution(land):
    oils = []
    total = [0]*len(land[0])
    
    for i in range(len(land)) :
        for j in range(len(land[0])):
            if land[i][j] == 1 :
                oils.append((i,j))
    visited = [[False]*len(land[0]) for _ in range(len(land))]
    
    def dfs(x,y,point,sichu):
        point += 1
        visited[x][y] = True
        for dx,dy in [(0,1),(0,-1),(1,0),(-1,0)] :
            nx, ny = x+dx, y+dy
            if 0<=nx<len(land) and 0<=ny<len(land[0]) and  visited[nx][ny] ==False and land[nx][ny] == 1:
                point = dfs(nx,ny,point,sichu)
        sichu[y] = point
        return point
    
    for x,y in oils:
        point = 0
        sichu = [0]*len(land[0])
        if visited[x][y] == False :
            dfs(x,y,point,sichu)
            for i in range(len(land[0])):
                total[i] += sichu[i]
    
    answer = max(total)
    return answer
