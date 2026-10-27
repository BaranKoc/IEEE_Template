class Solution:

    def findRotateSteps(self, ring: str, key: str) -> int:
        locs = {}
        for i, ch in enumerate(ring):
            locs.setdefault(ch, []).append(i)

        @cache
        def fn(i, j):
            if j == len(key):
                return 0
            loc = locs[key[j]]
            k = bisect_left(loc, i) % len(loc)
            ans = min(abs(i - loc[k]), len(ring) - abs(i - loc[k])) + fn(loc[k], j + 1)
            k = (k - 1) % len(loc)
            ans = min(ans, min(abs(i - loc[k]), len(ring) - abs(i - loc[k])) + fn(loc[k], j + 1))
            return ans
        return fn(0, 0) + len(key)
