class Solution:

    def canJump(self, nums: List[int]) -> bool:
        reachable = 0
        for i in range(len(nums)):
            if i > reachable:
                return False
            reachable = max(reachable, nums[i] + i)
            if reachable >= len(nums) - 1:
                break
        return True
