INF = 999999999
dp = [INF] * 1000003

X = int(input())

dp[X] = 0


def solve(x):
    if x > 1 and dp[x-1] > dp[x] + 1:
        dp[x-1] = dp[x] + 1
        solve(x-1)
    if x % 2 == 0 and dp[x//2] > dp[x] + 1:
        dp[x//2] = dp[x] + 1
        solve(x//2)
    if x % 3 == 0 and dp[x//3] > dp[x] + 1:
        dp[x//3] = dp[x] + 1
        solve(x//3)


solve(X)

print(dp[1])
