def solve():
    a, b, c = map(int, input().split())
    dp = [[[0.0 for _ in range(101)] for _ in range(101)] for _ in range(101)]
    dp[a][b][c] = 1.0
    for i in range(a, 100):
        for j in range(b, 100):
            for k in range(c, 100):
                total = i + j + k
                if total == 0:
                    continue
                dp[i + 1][j][k] += dp[i][j][k] * i / total
                dp[i][j + 1][k] += dp[i][j][k] * j / total
                dp[i][j][k + 1] += dp[i][j][k] * k / total

    res = 0.0
    for i in range(100):
        for j in range(100):
            res += dp[100][i][j] * (100 - a + i - b + j - c)
            res += dp[i][100][j] * (i - a + 100 - b + j - c)
            res += dp[i][j][100] * (i - a + j - b + 100 - c)
    print(f"{res:.6f}")
solve()