class Solution:

    def runningSum(self, nums: List[int]) -> List[int]:
        tot = 0
        ans = []
        for ele in nums:
            tot += ele
            ans.append(tot)
        return ans
