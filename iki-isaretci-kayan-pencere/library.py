from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class MinSubarrayWindow:

    def minSubArrayLen(self, target, nums):
        l, ans = (0, len(nums) + 1)
        s = 0
        for r in range(len(nums)):
            s += nums[r]
            while s >= target:
                ans = min(ans, r - l + 1)
                s -= nums[l]
                l += 1
        if ans == len(nums) + 1:
            return 0
        return ans

__all__ = ['MinSubarrayWindow']
