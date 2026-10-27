class Solution:

    def leftRightDifference(self, nums: List[int]) -> List[int]:
        return [abs(sum(nums[:i + 1]) - sum(nums[i:])) for i in range(len(nums))]
