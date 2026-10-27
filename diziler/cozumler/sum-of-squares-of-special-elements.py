class Solution:

    def sumOfSquares(self, nums: List[int]) -> int:
        return sum([num * num for index, num in enumerate(nums) if len(nums) % (index + 1) == 0])
