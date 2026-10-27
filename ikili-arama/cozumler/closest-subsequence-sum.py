class Solution:

    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        if goal == 0:
            return 0
        n = len(nums)
        mid = n // 2
        leftList = nums[:mid]
        leftSums = []
        rightList = nums[mid:]
        rightSums = []

        def buildSubsetSums(usedNums, numsToChooseFrom, ind, storeIn):
            if ind == len(numsToChooseFrom):
                storeIn.append(sum(usedNums))
                return
            usedNums.append(numsToChooseFrom[ind])
            buildSubsetSums(usedNums, numsToChooseFrom, ind + 1, storeIn)
            usedNums.pop()
            buildSubsetSums(usedNums, numsToChooseFrom, ind + 1, storeIn)
        buildSubsetSums([], leftList, 0, leftSums)
        buildSubsetSums([], rightList, 0, rightSums)
        rightSums.sort()
        diff = float('inf')
        for leftSum in leftSums:
            complement = goal - leftSum
            idx = bisect.bisect_left(rightSums, complement)
            for i in [idx - 1, idx, idx + 1]:
                if 0 <= i < len(rightSums):
                    finalSum = leftSum + rightSums[i]
                    diff = min(diff, abs(goal - finalSum))
        return diff
