class Solution:
    from collections import defaultdict

    def isPossible(self, nums):
        if len(nums) < 3:
            return False
        count = defaultdict(int)
        tails = defaultdict(int)
        for num in nums:
            count[num] += 1
        for num in nums:
            if count[num] == 0:
                continue
            elif tails[num - 1] > 0:
                tails[num - 1] -= 1
                tails[num] += 1
            elif count[num + 1] > 0 and count[num + 2] > 0:
                count[num + 1] -= 1
                count[num + 2] -= 1
                tails[num + 2] += 1
            else:
                return False
            count[num] -= 1
        return True
