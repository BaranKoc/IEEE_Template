from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class DuplicateDetector:

    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))

__all__ = ['DuplicateDetector']
