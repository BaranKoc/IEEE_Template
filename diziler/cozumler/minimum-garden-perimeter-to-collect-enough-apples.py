class Solution:

    def minimumPerimeter(self, nap: int) -> int:
        n = 1
        val = 2 * n * (n + 1) * (2 * n + 1)
        while val < nap:
            n += 1
            val = val = 2 * n * (n + 1) * (2 * n + 1)
        return n * 8
