class Solution:

    def longestSubarray(self, nums: List[int], limit: int) -> int:
        q = collections.deque()
        q2 = collections.deque()
        res = left = 0
        for right in range(len(nums)):
            while q and nums[q[-1]] <= nums[right]:
                q.pop()
            q.append(right)
            while q2 and nums[q2[-1]] >= nums[right]:
                q2.pop()
            q2.append(right)
            while left < right and q and q2 and (nums[q[0]] - nums[q2[0]] > limit):
                if q and q[0] == left:
                    q.popleft()
                if q2 and q2[0] == left:
                    q2.popleft()
                left += 1
            if nums[q[0]] - nums[q2[0]] <= limit:
                res = max(res, right - left + 1)
        return res
