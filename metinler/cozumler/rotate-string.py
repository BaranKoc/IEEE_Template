class Solution:

    def rotateString(self, s: str, goal: str) -> bool:
        for x in range(len(s)):
            s = s[-1] + s[:-1]
            if goal == s:
                return True
        return False
