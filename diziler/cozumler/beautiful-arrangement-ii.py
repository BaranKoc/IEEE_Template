class Solution:

    def constructArray(self, n: int, k: int) -> List[int]:
        res = list(range(1, n - k + 1))
        sign, val = (1, k)
        for i in range(k):
            res.append(res[-1] + sign * val)
            sign *= -1
            val -= 1
        return res
