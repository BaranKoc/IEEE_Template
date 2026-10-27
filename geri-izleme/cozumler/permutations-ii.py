class Solution(object):

    def permuteUnique(self, nums):
        if len(nums) == 1:
            return [[nums[0]]]
        res = self.permuteUnique(nums[1:])
        for i in range(len(res) - 1, -1, -1):
            j = 0
            while j < len(res[i]):
                if res[i][j] == nums[0]:
                    break
                lst = res[i][:]
                lst.insert(j, nums[0])
                res.append(lst)
                j += 1
            res[i].insert(j, nums[0])
        return res
