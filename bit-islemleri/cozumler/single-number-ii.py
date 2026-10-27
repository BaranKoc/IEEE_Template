import math

class Solution(object):

    def singleNumber(self, nums):
        total = sum(nums)
        uniqueTotals = set()
        while nums:
            uniqueTotals.add(nums.pop())
        return (sum(uniqueTotals) * 3 - total) / 2
