class Solution:

    def findUnsortedSubarray(self, nums) -> int:
        stack = []
        min_index = len(nums)
        max_index = 0
        max_pop = float('-inf')
        for i in range(len(nums)):
            while stack and nums[i] < stack[-1][0]:
                p = stack.pop()
                if p[0] > max_pop:
                    max_pop = p[0]
                if p[1] < min_index:
                    min_index = p[1]
                if p[1] > max_index:
                    max_index = p[1]
            stack.append([nums[i], i])
        max_r = max_index
        for st in stack:
            if st[0] < max_pop:
                max_r = st[1]
        if min_index == len(nums):
            return 0
        return max_r - min_index + 1
