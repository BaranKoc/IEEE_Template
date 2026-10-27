class Solution:

    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        q = []
        for i, n in enumerate(nums2):
            heapq.heappush(q, (-n, i))
        n = len(nums1)
        l = 0
        r = n - 1
        ans = [0] * n
        while q:
            num, i = heapq.heappop(q)
            num = -num
            if nums1[r] <= num:
                ans[i] = nums1[l]
                l += 1
            else:
                ans[i] = nums1[r]
                r -= 1
        return ans
