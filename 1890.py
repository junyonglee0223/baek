
n = int(input())
board = []

dp = [[0] * (n) for _ in range(n)]
for _ in range(n):
    row = list(map(int, input().split()))
    board.append(row)
dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            break
        if dp[i][j] > 0:
            if i + board[i][j] < n:
                dp[i+board[i][j]][j] += dp[i][j]
            if j + board[i][j] < n:
                dp[i][j+board[i][j]] += dp[i][j]

print(dp[n-1][n-1])

