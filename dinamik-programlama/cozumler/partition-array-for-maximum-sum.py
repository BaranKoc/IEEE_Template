class Solution:

    def maxSumAfterPartitioning(self, nums: List[int], k: int) -> int:

        def get_max(start, end):
            return max(nums[start:end + 1]) * (end - start + 1)

        def dfs(start):
            if start == N:
                return 0
            maxi = float(-inf)
            for end in range(start, min(N, start + k)):
                maxi = max(maxi, get_max(start, end) + dfs(end + 1))
            return maxi
        N = len(nums)
        return dfs(0)
