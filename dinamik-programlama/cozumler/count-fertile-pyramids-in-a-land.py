class Solution:

    def countPyramids(self, grid):
        m, n, dp, cnt = (len(grid), len(grid[0]), copy.deepcopy(grid), 0)
        for i in range(m - 2, -1, -1):
            for j in range(1, n - 1):
                if dp[i][j] > 0 and dp[i + 1][j] > 0:
                    dp[i][j] = min(dp[i + 1][j - 1], dp[i + 1][j + 1]) + 1
                    cnt += dp[i][j] - 1
        dp = grid
        for i in range(1, m):
            for j in range(1, n - 1):
                if dp[i][j] > 0 and dp[i - 1][j] > 0:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + 1
                    cnt += dp[i][j] - 1
        return cnt
