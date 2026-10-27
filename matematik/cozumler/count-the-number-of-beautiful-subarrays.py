class Solution(object):

    def beautifulSubarrays(self, nums):
        prefix = nums[0]
        hashmap = defaultdict(int)
        hashmap[0] = 1
        cnt = 0
        for i in xrange(0, len(nums)):
            if i > 0:
                prefix = nums[i] ^ prefix
            if prefix in hashmap:
                cnt += hashmap[prefix]
            hashmap[prefix] += 1
        return cnt
