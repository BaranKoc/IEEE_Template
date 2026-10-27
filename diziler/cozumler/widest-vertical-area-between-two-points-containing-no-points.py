class Solution:

    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        arr = [i[0] for i in points]
        arr.sort()
        diff = -1
        for i in range(1, len(arr)):
            diff = max(diff, arr[i] - arr[i - 1])
        return diff
