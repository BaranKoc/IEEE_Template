class Solution:

    def minLength(self, s: str) -> int:
        prev = len(s) + 1
        while len(s) < prev:
            s, prev = (s.replace('AB', '').replace('CD', ''), len(s))
        return prev
