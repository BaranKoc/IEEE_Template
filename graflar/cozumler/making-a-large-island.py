class Solution:

    def largestIsland(self, grid: List[List[int]]) -> int:
        m, n = (len(grid), len(grid[0]))
        parent = list(range(m * n))
        rank = [1 for _ in range(m * n)]

        def find(x):
            while x != parent[x]:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def union(x, y):
            parX, parY = (find(x), find(y))
            if parX == parY:
                return
            if rank[parX] >= rank[parY]:
                rank[parX] += rank[parY]
                parent[parY] = parX
            else:
                rank[parY] += rank[parX]
                parent[parX] = parY
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if not val:
                    rank[i * m + j] = 0
                    continue
                for x, y in [(i - 1, j), (i + 1, j), (i, j + 1), (i, j - 1)]:
                    if not (0 <= x < m and 0 <= y < n):
                        continue
                    if grid[x][y]:
                        union(i * m + j, x * m + y)
        ans = max(rank)
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val:
                    continue
                neighbours = set()
                res = 0
                for x, y in [(i - 1, j), (i + 1, j), (i, j + 1), (i, j - 1)]:
                    if not (0 <= x < m and 0 <= y < n):
                        continue
                    idx = x * m + y
                    neighbours.add(find(idx))
                for idx in neighbours:
                    res += rank[idx]
                ans = max(ans, res + 1)
        return ans
