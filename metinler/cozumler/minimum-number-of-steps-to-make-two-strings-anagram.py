class Solution:

    def minSteps(self, s: str, t: str) -> int:
        for ch in s:
            t = t.replace(ch, '', 1)
        return len(t)
