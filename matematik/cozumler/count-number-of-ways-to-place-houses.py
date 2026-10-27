class Solution:

    def countHousePlacements(self, n: int) -> int:

        @lru_cache(None)
        def rec(i, k):
            if i >= n:
                return 1
            elif k == 0:
                return rec(i + 1, 1) + rec(i + 1, 0)
            else:
                return rec(i + 1, 0)
        l1 = rec(1, 0) + rec(1, 1)
        mod = 10 ** 9 + 7
        return pow(l1, 2, mod)
