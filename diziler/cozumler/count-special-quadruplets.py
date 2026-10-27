class Solution:

    def countQuadruplets(self, nums: List[int]) -> int:
        return sum([1 for a, b, c, d in combinations(nums, 4) if a + b + c == d])
