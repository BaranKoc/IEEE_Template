class Solution:

    def twoEggDrop(self, n: int) -> int:
        return ceil(((1 + n * 8) ** 0.5 - 1) / 2)
