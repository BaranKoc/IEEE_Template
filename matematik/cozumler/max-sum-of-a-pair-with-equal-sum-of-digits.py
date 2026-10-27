class Solution:

    def maximumSum(self, nums: List[int]) -> int:
        d, mx = (defaultdict(list), -1)
        digits = lambda x: sum(map(int, list(str(x))))
        for n in nums:
            heappush(d[digits(n)], -n)
        for i in d:
            if len(d[i]) > 1:
                mx = max(mx, -heappop(d[i]) - heappop(d[i]))
        return mx
