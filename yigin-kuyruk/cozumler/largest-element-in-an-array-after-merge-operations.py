class Solution:

    def maxArrayValue(self, nums: List[int]) -> int:
        stack = []
        for n in reversed(nums):
            while stack and stack[-1] >= n:
                n += stack.pop()
            stack.append(n)
        return stack[-1]
