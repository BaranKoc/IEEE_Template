from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class AnagramChecker:

    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)

__all__ = ['AnagramChecker']
