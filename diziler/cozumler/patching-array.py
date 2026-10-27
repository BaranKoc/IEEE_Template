class Solution:

    def minPatches(self, nums: List[int], n: int) -> int:
        nums.append(n + 1)
        t = 1
        sum = 1
        rs = 0
        if nums[0] != 1:
            nums = [1] + nums
            rs += 1
        while sum < n:
            if sum < nums[t] - 1:
                sum += sum + 1
                rs += 1
            else:
                sum += nums[t]
                t += 1
        return rs
