class Solution:

    def reverseWords(self, s: str) -> str:
        s = s + ' '
        l = len(s)
        t = ''
        w = ''
        for i in range(l):
            if s[i] != ' ':
                t = s[i] + t
            else:
                w = w + t + ' '
                t = ''
        return w.strip()
