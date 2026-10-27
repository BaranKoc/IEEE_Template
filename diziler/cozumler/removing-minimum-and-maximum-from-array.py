class Solution:

    def minimumDeletions(self, nums: List[int]) -> int:
        minFromFront = nums.index(min(nums))
        maxFromFront = nums.index(max(nums))
        minFromBack = len(nums) - minFromFront - 1
        maxFromBack = len(nums) - maxFromFront - 1
        return min(max(minFromFront, maxFromFront) + 1, max(minFromBack, maxFromBack) + 1, minFromBack + maxFromFront + 2, minFromFront + maxFromBack + 2)
