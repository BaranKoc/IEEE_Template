class Solution:

    def numDupDigitsAtMostN(self, n: int) -> int:
        nums = [int(i) for i in str(n + 1)]
        d = len(nums)
        res = 0
        for i in range(1, d):
            res += 9 * math.perm(9, i - 1)
        for i, x in enumerate(nums):
            if i == 0:
                digit_range = range(1, x)
            else:
                digit_range = range(x)
            for y in digit_range:
                if y not in nums[:i]:
                    res += math.perm(9 - i, d - 1 - i)
            if x in nums[:i]:
                break
        return n - res
