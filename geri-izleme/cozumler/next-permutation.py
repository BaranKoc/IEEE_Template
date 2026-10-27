class Solution:

    def nextPermutation(self, nums) -> None:
        firstDecreasingElement = -1
        toSwapWith = -1
        lastIndex = len(nums) - 1
        for i in range(lastIndex, 0, -1):
            if nums[i] > nums[i - 1]:
                firstDecreasingElement = i - 1
                break
        if firstDecreasingElement == -1:
            for i in range(0, lastIndex // 2 + 1):
                nums[i], nums[lastIndex - i] = (nums[lastIndex - i], nums[i])
            return
        for i in range(lastIndex, 0, -1):
            if nums[i] > nums[firstDecreasingElement]:
                toSwapWith = i
                break
        nums[firstDecreasingElement], nums[toSwapWith] = (nums[toSwapWith], nums[firstDecreasingElement])
        left = firstDecreasingElement + 1
        right = lastIndex
        while left < right:
            nums[left], nums[right] = (nums[right], nums[left])
            left += 1
            right -= 1
