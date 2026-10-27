from functools import lru_cache, cache

class Solution:

    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:

        @cache
        def dp(i=0, m1=0, m2=0):
            if i == len(nums):
                return 0
            ans = 0
            for s in range(numSlots):
                if m2 & 1 << s == 0:
                    if m1 & 1 << s == 0:
                        nm1 = m1 | 1 << s
                        nm2 = m2
                    else:
                        nm1 = m1 & ~(1 << s)
                        nm2 = m2 | 1 << s
                    ans = max(ans, dp(i + 1, nm1, nm2) + (s + 1 & nums[i]))
            return ans
        return dp()
