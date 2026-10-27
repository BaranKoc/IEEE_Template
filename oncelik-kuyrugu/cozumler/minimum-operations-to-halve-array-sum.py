class Solution:

    def halveArray(self, nums: List[int]) -> int:
        maxHeap = []
        heapify(maxHeap)
        totalSum = 0
        for i in nums:
            heappush(maxHeap, -1 * i)
            totalSum += i
        requiredSum = totalSum / 2
        minOps = 0
        while totalSum > requiredSum:
            x = -1 * heappop(maxHeap)
            x /= 2
            totalSum -= x
            heappush(maxHeap, -1 * x)
            minOps += 1
        return minOps
