class Solution:

    def findMinDifference(self, timePoints: List[str]) -> int:
        minutes = sorted([int(time[:2]) * 60 + int(time[3:]) for time in timePoints])
        min_diff = float('inf')
        for i in range(len(minutes) - 1):
            diff = minutes[i + 1] - minutes[i]
            if diff < min_diff:
                min_diff = diff
        diff = (24 * 60 - minutes[-1] + minutes[0]) % (24 * 60)
        if diff < min_diff:
            min_diff = diff
        return min_diff
