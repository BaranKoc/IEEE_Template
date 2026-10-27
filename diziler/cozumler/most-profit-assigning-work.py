class Solution:

    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        arr = []
        for i in range(len(difficulty)):
            arr.append([difficulty[i], profit[i]])
        arr.sort(key=lambda x: x[0])
        maximum = float(-inf)
        for j in range(len(arr)):
            maximum = max(maximum, arr[j][1])
            arr[j][1] = maximum
        ans = 0
        for w in worker:
            bestProfit = 0
            L, R = (0, len(arr) - 1)
            while L <= R:
                mid = (L + R) // 2
                mid_e = arr[mid]
                if mid_e[0] <= w:
                    bestProfit = max(bestProfit, mid_e[1])
                    L = mid + 1
                    continue
                else:
                    R = mid - 1
                    continue
            ans += bestProfit
        return ans
