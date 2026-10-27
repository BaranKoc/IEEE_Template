class Solution:

    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if k == 1:
            return True
        nums.sort()
        q = deque()
        for n in nums:
            if not q or q[0][0] > n:
                q.append((n + 1, k - 2))
            elif q[0][0] == n:
                _, rem = q.popleft()
                if rem:
                    q.append((n + 1, rem - 1))
            else:
                return False
        if q:
            return False
        else:
            return True
