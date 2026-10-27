class Solution:

    def sumOfFlooredPairs(self, nums: List[int]) -> int:
        incs, counter = ([0] * (max(nums) + 1), Counter(nums))
        for num in counter:
            for j in range(num, len(incs), num):
                incs[j] += counter[num]
        quots = list(accumulate(incs))
        return sum([quots[num] for num in nums]) % 1000000007
