class Solution:

    def numOfSubarrays(self, nums: List[int], k: int, threshold: int) -> int:
        currSum = 0
        start = 0
        end = 0
        count = 0
        for end in range(len(nums)):
            currSum += nums[end]
            if end - start + 1 == k:
                if currSum // k >= threshold:
                    count += 1
                currSum -= nums[start]
                start += 1
        return count
