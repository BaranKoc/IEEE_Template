class Solution:

    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        target = sum(nums) % p
        if not target:
            return 0
        answer = n
        prefix_sum = 0
        hashmap = {0: -1}
        for i, num in enumerate(nums):
            prefix_sum += num
            key = (prefix_sum % p - target) % p
            if key in hashmap:
                answer = min(answer, i - hashmap[key])
            hashmap[prefix_sum % p] = i
        return answer if answer < n else -1
