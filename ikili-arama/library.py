from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class SortedSearch:

    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return -1

__all__ = ['SortedSearch']
