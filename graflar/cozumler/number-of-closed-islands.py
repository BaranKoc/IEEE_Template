class Solution:

    def closedIsland(self, grid: List[List[int]]) -> int:
        result = 0
        m, n = (len(grid), len(grid[0]))
        self.direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        for j in range(n):
            self.dfs(grid, 0, j)
            self.dfs(grid, m - 1, j)
        for i in range(m):
            self.dfs(grid, i, 0)
            self.dfs(grid, i, n - 1)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    result += 1
                    self.dfs(grid, i, j)
        return result

    def dfs(self, grid, i, j):
        m, n = (len(grid), len(grid[0]))
        if i < 0 or j < 0 or i >= m or (j >= n):
            return
        if grid[i][j] == 1:
            return
        grid[i][j] = 1
        for d in self.direction:
            x = i + d[0]
            y = j + d[1]
            self.dfs(grid, x, y)
