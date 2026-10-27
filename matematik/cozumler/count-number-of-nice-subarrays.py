class Solution(object):

    def numberOfSubarrays(self, nums, k):
        odds = []
        for i in range(len(nums)):
            if nums[i] & 1:
                odds.append(i)
        odds = [-1] + odds + [len(nums)]
        nice = 0
        for i in range(1, len(odds) - k):
            left = odds[i] - odds[i - 1] - 1
            right = odds[i + k] - odds[i + k - 1] - 1
            nice += (left + 1) * (right + 1)
        return nice
