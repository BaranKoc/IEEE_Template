class Solution:

    def kidsWithCandies(self, candy, extra):
        res = [True] * len(candy)
        for i in range(len(candy)):
            if candy[i] + extra >= max(candy):
                continue
            else:
                res[i] = False
        return res
