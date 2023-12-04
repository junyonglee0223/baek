n = int(input())
stair = [0] + [int(input()) for _ in range(n)]  

dp = [[0]*3 for _ in range(n+1)]
dp[1][1] = stair[1]

for i in range(2, n+1):
    dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + stair[i]
    dp[i][1] = dp[i-1][0] + stair[i]
    dp[i][2] = max(dp[i-1][0], dp[i-1][2])

print(max(dp[n][0], dp[n][1], dp[n][2]))
