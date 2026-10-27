class Solution:

    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m, n = (len(grid), len(grid[0]))
        dp = [[(0, 0)] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if not grid[i][j]:
                    continue
                dp[i][j] = (dp[i][j][0] + dp[i - 1][j][0] + 1, dp[i][j][1] + dp[i][j - 1][1] + 1)
        for win in range(min(m, n) - 1, -1, -1):
            for i in range(m - win):
                for j in range(n - win):
                    if not grid[i][j]:
                        continue
                    x1, y1 = dp[i + win][j + win]
                    x2, y2 = dp[i][j + win]
                    x3, y3 = dp[i + win][j]
                    x4, y4 = dp[i][j]
                    if y1 - y3 == x1 - x2 == y2 - y4 == x3 - x4 == win:
                        return (win + 1) * (win + 1)
        return 0
