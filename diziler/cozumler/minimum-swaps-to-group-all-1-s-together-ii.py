class Solution:

    def minSwaps(self, nums: List[int]) -> int:
        width = sum((num == 1 for num in nums))
        nums += nums
        res = width
        curr_zeros = sum((num == 0 for num in nums[:width]))
        for i in range(width, len(nums)):
            curr_zeros -= nums[i - width] == 0
            curr_zeros += nums[i] == 0
            res = min(res, curr_zeros)
        return res
