class Solution(object):

    def recoverArray(self, nums):
        nums.sort()
        mid = len(nums) // 2
        for j in range(1, mid + 1):
            if nums[j] - nums[0] > 0 and (nums[j] - nums[0]) % 2 == 0:
                k, counter, ans = ((nums[j] - nums[0]) // 2, collections.Counter(nums), [])
                for n in nums:
                    if counter[n] == 0:
                        continue
                    if counter[n + 2 * k] == 0:
                        break
                    ans.append(n + k)
                    counter[n] -= 1
                    counter[n + 2 * k] -= 1
                if len(ans) == mid:
                    return ans
