class Solution:

    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        prefix_sums = {0}
        res = prefix_sum = 0
        for num in nums:
            prefix_sum += num
            if prefix_sum - target in prefix_sums:
                res += 1
                prefix_sums = {prefix_sum}
            else:
                prefix_sums.add(prefix_sum)
        return res
