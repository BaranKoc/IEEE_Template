class Solution:

    def concatenatedBinary(self, n: int) -> int:
        modulo = 10 ** 9 + 7
        shift = 0
        res = 0
        for i in range(1, n + 1):
            if i & i - 1 == 0:
                shift += 1
            res = ((res << shift) + i) % modulo
        return res
