from itertools import accumulate

class Solution(object):

    def getSumAbsoluteDifferences(self, nums):
        total, n = (sum(nums), len(nums))
        return [(i + 1) * num - pref + (total - pref - (n - i - 1) * num) for (i, num), pref in zip(enumerate(nums), list(accumulate(nums)))]
