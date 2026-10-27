class Solution:

    def numWays(self, s: str) -> int:
        ones = 0
        for char in s:
            if char == '1':
                ones += 1
        if ones > 0 and ones % 3 != 0:
            return 0
        if ones == 0:
            n = len(s)
            return (n - 1) * (n - 2) // 2 % (10 ** 9 + 7)
        ones_interval = ones // 3
        left, right = (0, 0)
        i = 0
        temp = 0
        while i < len(s):
            temp += int(s[i]) & 1
            if temp == ones_interval:
                if s[i] == '0':
                    left += 1
            if temp == 2 * ones_interval:
                if s[i] == '0':
                    right += 1
            i += 1
        return (left + 1) * (right + 1) % (10 ** 9 + 7)
