class Solution:

    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        m = len(mat)
        n = len(mat[0])
        dp = defaultdict(defaultdict)
        for i in range(m):
            mat[i] = sorted(mat[i])
        globalMin = float('inf')

        def findMinAbsDiff(i, prevSum):
            nonlocal globalMin
            if i == m:
                globalMin = min(globalMin, abs(prevSum - target))
                return abs(prevSum - target)
            if prevSum - target > globalMin:
                return float('inf')
            if i in dp and prevSum in dp[i]:
                return dp[i][prevSum]
            minDiff = float('inf')
            for j in range(n):
                diff = findMinAbsDiff(i + 1, prevSum + mat[i][j])
                if diff == 0:
                    minDiff = 0
                    break
                minDiff = min(minDiff, diff)
            dp[i][prevSum] = minDiff
            return minDiff
        return findMinAbsDiff(0, 0)
