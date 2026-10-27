class Solution:

    def countBits(self, n: int) -> List[int]:
        dp = [0]
        for i in range(1, n + 1):
            exponent = int(math.log(i) / math.log(2))
            num = 2 ** exponent
            decimal = i % num
            if num == i:
                dp.append(1)
            else:
                dp.append(dp[num] + dp[decimal])
        return dp
