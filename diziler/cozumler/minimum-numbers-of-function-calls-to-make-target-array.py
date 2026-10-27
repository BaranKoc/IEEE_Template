class Solution:

    def minOperations(self, nums: List[int]) -> int:
        if max(nums) == 0:
            return 0
        return sum([x.bit_count() for x in nums]) + max([x.bit_length() for x in nums]) - 1
