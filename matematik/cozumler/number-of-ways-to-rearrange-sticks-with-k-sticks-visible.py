M = 10 ** 9 + 7
from functools import cache

class Solution:

    def rearrangeSticks(self, n: int, k: int) -> int:
        return dp(n, k)

@cache
def dp(n, k):
    if n == k:
        return 1
    if n <= 0 or k <= 0:
        return 0
    return (dp(n - 1, k - 1) + (n - 1) * dp(n - 1, k)) % M
