class Solution:

    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        m, n = (len(cost), len(cost[0]))
        mn = [min(x) for x in zip(*cost)]

        @lru_cache(None)
        def fn(i, mask):
            if i == m:
                return sum((mn[j] for j in range(n) if not mask & 1 << j))
            return min((cost[i][j] + fn(i + 1, mask | 1 << j) for j in range(n)))
        return fn(0, 0)
