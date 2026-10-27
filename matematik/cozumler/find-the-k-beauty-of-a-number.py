class Solution:

    def divisorSubstrings(self, num: int, k: int) -> int:
        numStr = str(num)
        i, k_beauty = (0, 0)
        while i + k - 1 < len(numStr):
            n = int(numStr[i:i + k])
            if n != 0 and num % n == 0:
                k_beauty += 1
            i += 1
        return k_beauty
