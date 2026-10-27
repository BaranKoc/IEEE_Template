from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class BalancedBrackets:

    def isValid(self, string: str) -> bool:
        while True:
            if '()' in string:
                string = string.replace('()', '')
            elif '{}' in string:
                string = string.replace('{}', '')
            elif '[]' in string:
                string = string.replace('[]', '')
            else:
                return not string

class NextWarmerDay:

    def dailyTemperatures(self, T):
        ans, s = ([0] * len(T), deque())
        for cur, cur_tmp in enumerate(T):
            while s and cur_tmp > T[s[-1]]:
                ans[s[-1]] = cur - s[-1]
                s.pop()
            s.append(cur)
        return ans

__all__ = ['BalancedBrackets', 'NextWarmerDay']
