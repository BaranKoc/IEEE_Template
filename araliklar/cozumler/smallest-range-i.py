class Solution:

    def smallestRangeI(self, A: List[int], K: int) -> int:
        maxi = max(A)
        mini = min(A)
        return max(0, maxi - K - mini - K)
