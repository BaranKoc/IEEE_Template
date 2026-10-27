from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class MergeIntervals:

    def merge(self, A: List[List[int]]) -> List[List[int]]:
        A.sort(key=lambda x: x[0])
        i = 0
        while i < len(A) - 1:
            if A[i][1] >= A[i + 1][0]:
                A[i][1] = max(A[i + 1][1], A[i][1])
                A.pop(i + 1)
            else:
                i += 1
        return A

class PrefixSumArray:

    def __init__(self, nums: List[int]):
        self.nums, Sum = ([], 0)
        for num in nums:
            Sum += num
            self.nums.append(Sum)

    def sumRange(self, left: int, right: int) -> int:
        return self.nums[right] - self.nums[left - 1] if left - 1 >= 0 else self.nums[right]

__all__ = ['MergeIntervals', 'PrefixSumArray']
