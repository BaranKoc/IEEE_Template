class Solution:

    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        result = self.function(spells, potions, success)
        return result

    def function(self, arr1, arr2, success):
        n2 = len(arr2)
        arr2.sort()
        ans = []
        for i in arr1:
            val = math.ceil(success / i)
            idx = bisect.bisect_left(arr2, val)
            res = n2 - idx + 1
            ans.append(res - 1)
        return ans
