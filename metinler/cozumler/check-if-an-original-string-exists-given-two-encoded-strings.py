from functools import lru_cache

class Solution:

    def possiblyEquals(self, s1: str, s2: str) -> bool:

        def getValidPrefixLength(s, start):
            end = start
            while end < len(s) and s[end].isdigit():
                end += 1
            return end

        @lru_cache(None)
        def possibleLengths(s):
            ans = {int(s)}
            for i in range(1, len(s)):
                ans |= {x + y for x in possibleLengths(s[:i]) for y in possibleLengths(s[i:])}
            return ans

        @lru_cache(None)
        def dp(i, j, diff):
            if i == len(s1) and j == len(s2):
                return diff == 0
            if i < len(s1) and s1[i].isdigit():
                i2 = getValidPrefixLength(s1, i)
                for L in possibleLengths(s1[i:i2]):
                    if dp(i2, j, diff - L):
                        return True
            elif j < len(s2) and s2[j].isdigit():
                j2 = getValidPrefixLength(s2, j)
                for L in possibleLengths(s2[j:j2]):
                    if dp(i, j2, diff + L):
                        return True
            elif diff == 0:
                if i == len(s1) or j == len(s2) or s1[i] != s2[j]:
                    return False
                return dp(i + 1, j + 1, 0)
            elif diff > 0:
                if i == len(s1):
                    return False
                return dp(i + 1, j, diff - 1)
            else:
                if j == len(s2):
                    return False
                return dp(i, j + 1, diff + 1)
        return dp(0, 0, 0)
