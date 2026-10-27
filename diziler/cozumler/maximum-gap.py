class Solution:

    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        longest = 0
        for i in nums:
            longest = max(longest, len(str(i)))
        for i in range(len(nums)):
            if len(str(nums[i])) != longest:
                nums[i] = '0' * (longest - len(str(nums[i]))) + str(nums[i])
            else:
                nums[i] = str(nums[i])
        for digit in range(longest - 1, -1, -1):
            vals = [[] for k in range(10)]
            for num in nums:
                vals[int(num[digit])] += [num]
            new = []
            for i in vals:
                new += i
            nums = new.copy()
        best_diff = 0
        for i in range(1, len(nums)):
            best_diff = max(best_diff, int(nums[i]) - int(nums[i - 1]))
        return best_diff
