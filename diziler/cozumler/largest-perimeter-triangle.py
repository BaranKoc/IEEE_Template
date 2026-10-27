class Solution:

    def largestPerimeter(self, nums: List[int]) -> int:
        nums = sorted(nums, reverse=True)
        l = len(nums)
        for i in range(l - 2):
            if nums[i] < nums[i + 1] + nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0
