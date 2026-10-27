class Solution:

    def maxEqualFreq(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        countToFreq = defaultdict(int)
        freqToCount = defaultdict(int)
        for i, val in enumerate(nums):
            x = countToFreq[val] + 1
            freqToCount[x - 1] -= 1
            if freqToCount[x - 1] <= 0:
                freqToCount.pop(x - 1)
            freqToCount[x] += 1
            countToFreq[val] = x
            if countToFreq[val] == i + 1:
                ans = i + 1
            elif i < n - 1 and len(freqToCount) == 1 or (len(freqToCount) == 1 and max(freqToCount.keys()) == 1):
                ans = i + 1
            elif len(freqToCount) == 2 and 1 in freqToCount and (freqToCount[1] == 1):
                ans = i + 1
            elif len(freqToCount) == 2:
                keys, values = ([], [])
                for j in freqToCount:
                    (keys.append(j), values.append(freqToCount[j]))
                if keys[0] == 1 + keys[1] and values[0] == 1 or (keys[1] == 1 + keys[0] and values[1] == 1):
                    ans = i + 1
        return ans
