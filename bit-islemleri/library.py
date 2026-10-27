from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class BitCounter:

    def hammingWeight(self, n: int) -> int:
        i = 0
        while n > 0:
            if n % 2 != 0:
                i += 1
            n = n >> 1
        return i

class SingleNumber:

    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        i = 0
        while i < len(nums) - 1:
            if nums[i] == nums[i + 1]:
                i += 2
            else:
                return nums[i]
        return nums[-1]

__all__ = ['BitCounter', 'SingleNumber']
