from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class SubsetEnumerator:

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.final_list = []

        def subset(final_list, curr_list, listt, i):
            if i == len(listt):
                final_list.append(curr_list)
                return
            else:
                subset(final_list, curr_list, listt, i + 1)
                subset(final_list, curr_list + [listt[i]], listt, i + 1)
        subset(self.final_list, [], nums, 0)
        return self.final_list

__all__ = ['SubsetEnumerator']
