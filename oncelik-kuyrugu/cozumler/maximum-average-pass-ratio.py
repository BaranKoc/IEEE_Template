class Solution:

    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        n = len(classes)
        impacts = [0] * n
        minRatioIndex = 0
        for i in range(n):
            passCount = classes[i][0]
            totalCount = classes[i][1]
            currentRatio = passCount / totalCount
            expectedRatioAfterUpdate = (passCount + 1) / (totalCount + 1)
            impact = expectedRatioAfterUpdate - currentRatio
            impacts[i] = (-impact, passCount, totalCount)
        heapq.heapify(impacts)
        while extraStudents > 0:
            _, passCount, totalCount = heapq.heappop(impacts)
            passCount += 1
            totalCount += 1
            currentRatio = passCount / totalCount
            expectedRatioAfterUpdate = (passCount + 1) / (totalCount + 1)
            impact = expectedRatioAfterUpdate - currentRatio
            heapq.heappush(impacts, (-impact, passCount, totalCount))
            extraStudents -= 1
        result = 0
        for _, passCount, totalCount in impacts:
            result += passCount / totalCount
        return result / n
