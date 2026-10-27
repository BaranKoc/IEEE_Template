class Solution:

    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        m = n // 2

        @lru_cache(None)
        def dfs(cur, a):
            if cur == n:
                return 0
            b = cur - a
            ans = float('inf')
            if a < m:
                ans = min(dfs(cur + 1, a + 1) + costs[cur][0], ans)
            if b < m:
                ans = min(dfs(cur + 1, a) + costs[cur][1], ans)
            return ans
        return dfs(0, 0)
