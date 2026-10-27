class Solution:

    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        loc = defaultdict(list)
        for i, num in enumerate(nums):
            loc[num].append(i)
        k = sorted(loc)
        res = []
        for a, b in queries:
            cands = []
            ans = float('inf')
            for c in k:
                if bisect.bisect_left(loc[c], a) == bisect.bisect(loc[c], b):
                    continue
                if cands:
                    ans = min(ans, c - cands[-1])
                cands.append(c)
            if ans == float('inf'):
                ans = -1
            res.append(ans)
        return res
