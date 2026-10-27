class Solution:

    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        l = []
        if finalSum % 2 != 0:
            return l
        else:
            s = 0
            i = 2
            while s < finalSum:
                s += i
                l.append(i)
                i += 2
            if s == finalSum:
                return l
            else:
                l.pop(l.index(s - finalSum))
            return l
