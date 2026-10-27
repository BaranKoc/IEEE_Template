class Solution:

    def convertToTitle(self, num: int) -> str:
        alpha = [chr(x) for x in range(ord('A'), ord('Z') + 1)]
        res = ''
        while num > 0:
            res += alpha[(num - 1) % 26]
            num = (num - 1) // 26
        return res[::-1]
