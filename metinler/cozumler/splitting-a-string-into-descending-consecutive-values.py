class Solution:

    def splitString(self, s: str, last_val: int=None) -> bool:
        if last_val and int(s) == last_val - 1:
            return True
        for i in range(1, len(s)):
            cur = int(s[:i])
            if last_val is None or cur == last_val - 1:
                if self.splitString(s[i:], cur):
                    return True
        return False
