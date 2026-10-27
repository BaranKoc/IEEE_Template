class Solution:

    def kadanes(self, nums):
        max_till_now = nums[0]
        curr_max = nums[0]
        for i in range(1, len(nums)):
            curr_max = max(curr_max + nums[i], nums[i])
            max_till_now = max(max_till_now, curr_max)
        return max_till_now

    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total = sum(nums)
        nonwrappingsum = self.kadanes(nums)
        if nonwrappingsum < 0:
            return nonwrappingsum
        for i in range(len(nums)):
            nums[i] *= -1
        wrappingsum = total - -self.kadanes(nums)
        return max(nonwrappingsum, wrappingsum)
