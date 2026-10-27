class Solution:

    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        res = []
        minSide = 0
        maxLen = 0
        for l, w in rectangles:
            minSide = min(l, w)
            if minSide > maxLen:
                maxLen = minSide
            res.append(minSide)
        return res.count(maxLen)
