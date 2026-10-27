class Solution:

    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = {}

        def recursion(index, M):
            if index == n:
                return 0
            if (index, M) in dp:
                return dp[index, M]
            total = sum(piles[index:])
            if index + 2 * M >= n:
                return total
            my_score = 0
            for x in range(index, index + 2 * M):
                opponent_score = recursion(x + 1, max(M, x - index + 1))
                my_score = max(my_score, total - opponent_score)
            dp[index, M] = my_score
            return my_score
        return recursion(0, 1)
