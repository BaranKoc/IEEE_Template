from collections import defaultdict
import heapq

class Solution:

    def largestValsFromLabels(self, values: list[int], labels: list[int], numWanted: int, useLimit: int) -> int:
        heap = [(-value, label) for value, label in zip(values, labels)]
        heapq.heapify(heap)
        used = defaultdict(int)
        res = 0
        while numWanted > 0 and heap:
            value, label = heapq.heappop(heap)
            if used[label] < useLimit:
                res += -value
                used[label] += 1
                numWanted -= 1
        return res
