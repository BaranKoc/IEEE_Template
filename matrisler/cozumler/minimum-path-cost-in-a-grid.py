class Solution:

    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        max_row, max_col = (len(grid), len(grid[0]))
        dp = [[-1] * max_col for _ in range(max_row)]

        def recursion(row, col):
            if row == max_row - 1:
                return grid[row][col]
            if dp[row][col] == -1:
                current = grid[row][col]
                res = float('inf')
                for c in range(max_col):
                    val = moveCost[current][c] + recursion(row + 1, c)
                    res = min(res, val)
                dp[row][col] = res + current
            return dp[row][col]
        for c in range(max_col):
            recursion(0, c)
        return min(dp[0])
