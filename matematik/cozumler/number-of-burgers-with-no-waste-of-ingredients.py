class Solution(object):

    def numOfBurgers(self, t, c):
        if t == c == 0:
            return [0, 0]
        four = (t - 2 * c) // 2
        two = c - four
        if c >= t or (t - 2 * c) % 2 == 1 or four < 0 or (two < 0):
            return []
        return [four, two]
