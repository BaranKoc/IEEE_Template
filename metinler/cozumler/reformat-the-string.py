class Solution:

    def reformat(self, s: str) -> str:
        alpha = []
        num = []
        res = ''
        for i in s:
            if i.isalpha():
                alpha.append(i)
            else:
                num.append(i)
        if abs(len(alpha) - len(num)) > 1:
            return ''
        for ch, n in zip(alpha, num):
            res += ch + n
        if len(alpha) > len(num):
            res += alpha[-1]
        if len(num) > len(alpha):
            res = num[-1] + res
        return res
