class Solution:

    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        n = len(nums1)
        k = k1 + k2
        diffs = sorted((abs(x - y) for x, y in zip(nums1, nums2)))
        l, r = (0, max(diffs))
        while l < r:
            mid = (l + r) // 2
            steps = sum((max(0, num - mid) for num in diffs))
            if steps <= k:
                r = mid
            else:
                l = mid + 1
        newMax = l
        k -= sum((max(0, num - newMax) for num in diffs))
        l, r = (0, n - 1)
        while l < r:
            mid = (l + r) // 2
            if diffs[mid] < newMax:
                l = mid + 1
            else:
                r = mid
        diffs = diffs[:l] + [newMax] * (n - l)
        for i in range(len(diffs) - 1, -1, -1):
            if k == 0 or diffs[i] == 0:
                break
            diffs[i] -= 1
            k -= 1
        return sum((diff * diff for diff in diffs))
