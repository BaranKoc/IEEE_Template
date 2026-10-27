class Solution:

    def maxProduct(self, nums: List[int]) -> int:
        prod = 1
        maxprod = -100000000
        for i in range(len(nums)):
            prod *= nums[i]
            maxprod = max(maxprod, prod)
            if prod == 0:
                prod = 1
        prod = 1
        for i in range(len(nums) - 1, -1, -1):
            prod *= nums[i]
            maxprod = max(maxprod, prod)
            if prod == 0:
                prod = 1
        return maxprod
