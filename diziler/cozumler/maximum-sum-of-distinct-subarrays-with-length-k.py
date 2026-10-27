class Solution:

    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        res, cur, pos, dup = (0, 0, [-1] * 100001, -1)
        for i in range(0, len(nums)):
            cur += nums[i]
            if i >= k:
                cur -= nums[i - k]
            dup = max(dup, pos[nums[i]])
            if i - dup >= k:
                res = max(res, cur)
            pos[nums[i]] = i
        return res
