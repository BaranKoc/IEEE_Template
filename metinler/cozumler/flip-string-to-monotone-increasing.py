class Solution:

    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        min_flip = n
        one_left = 0
        zero_right = s.count('0')
        for i in range(n + 1):
            min_flip = min(min_flip, one_left + zero_right)
            if i == len(s):
                continue
            if s[i] == '0':
                zero_right -= 1
            else:
                one_left += 1
        return min_flip
