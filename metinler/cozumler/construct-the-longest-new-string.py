class Solution:

    def longestString(self, x: int, y: int, z: int) -> int:
        count = z * 2
        n = min(x, y)
        count += n * 4
        x -= n
        y -= n
        if x > 0 or y > 0:
            count += 2
        return count
