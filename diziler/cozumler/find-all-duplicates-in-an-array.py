class Solution:

    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        hm = {}
        for i, v in enumerate(nums):
            if v not in hm:
                hm[v] = 1
            else:
                hm[v] += 1
        for key, value in hm.items():
            if value > 1:
                res.append(key)
        return res
