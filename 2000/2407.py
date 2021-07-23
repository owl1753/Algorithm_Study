dp = [[0 for j in range(101)] for i in range(101)]

dp[0][0] = 1
for i in range(1, 101):
    dp[i][0] = 1
    dp[i][i] = 1
    for j in range(1, i):
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

n, m = map(int, input().split())

print(dp[n][m])