from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class PrimeCounter:

    def countPrimes(self, n: int) -> int:
        truth = [True] * n
        if n < 2:
            return 0
        truth[0], truth[1] = (False, False)
        i = 2
        while i * i < n:
            if truth[i] == True:
                for j in range(i * i, n, i):
                    truth[j] = False
            i += 1
        return truth.count(True)

__all__ = ['PrimeCounter']
