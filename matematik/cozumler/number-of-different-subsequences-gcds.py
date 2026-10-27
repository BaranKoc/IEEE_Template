import math

class Solution:

    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        max_n = max(nums) + 1
        seen = set(nums)
        ans = 0
        for k in range(1, max_n):
            gcd = 0
            for multiple in range(k, max_n, k):
                if multiple in seen:
                    gcd = math.gcd(gcd, multiple)
            if gcd == k:
                ans += 1
        return ans
