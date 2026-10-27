class Solution:

    def getMaximumConsecutive(self, coins: List[int]) -> int:
        cur_max = 0
        coins.sort()
        for coin in coins:
            if coin == 1:
                cur_max += 1
            elif coin <= cur_max + 1:
                cur_max += coin
            else:
                break
        return cur_max + 1
