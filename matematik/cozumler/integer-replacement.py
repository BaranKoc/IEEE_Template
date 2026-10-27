class Solution:

    def integerReplacement(self, n: int) -> int:
        dp = {}

        def dfs(num):
            if num == 1:
                return 0
            if num in dp:
                return dp[num]
            even = odd = 0
            if num % 2 == 0:
                even = 1 + dfs(num // 2)
            else:
                odd1 = 1 + dfs(num - 1)
                odd2 = 1 + dfs(num + 1)
                odd = min(odd1, odd2)
            dp[num] = even + odd
            return dp[num]
        return dfs(n)
