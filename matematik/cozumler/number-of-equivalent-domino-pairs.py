import math

class Solution:

    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        d = dict()
        for i in dominoes:
            i.sort()
            if tuple(i) in d.keys():
                d[tuple(i)] += 1
            else:
                d[tuple(i)] = 1
        count = 0
        for x, y in d.items():
            if y > 1:
                count += y * (y - 1) // 2
        return count
