class Solution:

    def winnerSquareGame(self, n: int) -> bool:
        squares = lambda x: (i * i for i in range(isqrt(x), 0, -1))

        @cache
        def can_win(n: int) -> bool:
            return n and (not all((can_win(n - s) for s in squares(n))))
        return can_win(n)
