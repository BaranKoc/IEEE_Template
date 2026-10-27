class Solution:

    def longestDupSubstring(self, s: str) -> str:
        left = 0
        right = 1
        res = ''
        n = len(s)
        while right < n:
            if s[left:right] in s[left + 1:]:
                if right - left > len(res):
                    res = s[left:right]
                right += 1
                continue
            left += 1
            if left == right:
                right += 1
        return res
