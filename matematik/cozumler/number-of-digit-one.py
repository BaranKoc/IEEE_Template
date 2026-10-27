class Solution:

    def countDigitOne(self, n: int) -> int:
        num = str(n)[::-1]
        count = 0
        for i in range(len(num) - 1, -1, -1):
            pv = 10 ** i
            mul = n // (pv * 10)
            rem = n % pv
            count += mul * pv
            if num[i] > '1':
                count += pv
            if num[i] == '1':
                count += rem + 1
        return count
