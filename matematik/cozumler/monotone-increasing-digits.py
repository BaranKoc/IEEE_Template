class Solution:

    def monotoneIncreasingDigits(self, n: int) -> int:
        num = list(str(n))
        for i in range(len(num) - 1):
            if num[i] > num[i + 1]:
                while i >= 1 and num[i - 1] == num[i]:
                    i -= 1
                num[i] = chr(ord(num[i]) - 1)
                return int(''.join(num[:i + 1] + ['9'] * (len(num) - i - 1)))
        return n
