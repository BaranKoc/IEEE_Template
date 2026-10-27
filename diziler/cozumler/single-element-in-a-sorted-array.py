class Solution:

    def singleNonDuplicate(self, nums: List[int]) -> int:
        return self.b_search(nums)[0]

    def b_search(self, nums):
        if len(nums) == 1:
            return nums
        mid = len(nums) // 2
        a = nums[:mid]
        b = nums[mid:]
        if a[-1] == b[0]:
            a = a[:-1]
            b = b[1:]
        if len(a) % 2:
            return self.b_search(a)
        else:
            return self.b_search(b)
