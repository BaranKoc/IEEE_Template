class Solution:

    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        req = n // 3
        c1 = 0
        c2 = 0
        me1 = None
        me2 = None
        for i in nums:
            if i == me1:
                c1 += 1
            elif i == me2:
                c2 += 1
            elif c1 == 0:
                me1 = i
                c1 = 1
            elif c2 == 0:
                me2 = i
                c2 = 1
            else:
                c1 -= 1
                c2 -= 1
        c1 = 0
        c2 = 0
        for i in nums:
            if i == me1:
                c1 += 1
            if i == me2:
                c2 += 1
        if c1 > req and c2 > req:
            return [me1, me2]
        elif c1 > req:
            return [me1]
        elif c2 > req:
            return [me2]
