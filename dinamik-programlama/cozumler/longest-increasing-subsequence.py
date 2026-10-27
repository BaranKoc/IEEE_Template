class Solution:

    def lengthOfLIS(self, nums: list[int]) -> int:
        res = []

        def binarySearch(l, r, target):
            nonlocal res
            if l == r:
                return l
            m = (r - l) // 2 + l
            if res[m] == target:
                return m
            elif res[m] < target:
                return binarySearch(m + 1, r, target)
            else:
                return binarySearch(l, m, target)
        for n in nums:
            if not res or res[-1] < n:
                res.append(n)
                continue
            i = binarySearch(0, len(res) - 1, n)
            res[i] = n
        return len(res)
