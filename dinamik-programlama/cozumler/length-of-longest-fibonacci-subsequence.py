class Solution(object):

    def lenLongestFibSubseq(self, A):
        index = {Ai: i for i, Ai in enumerate(A)}
        dp = collections.defaultdict(lambda: 2)
        ans = 0
        for k, Ak in enumerate(A):
            for j in range(k - 1, 0, -1):
                i = index.get(Ak - A[j], None)
                if Ak - A[j] >= A[j]:
                    break
                if i is not None and i < j:
                    cur_len = dp[j, k] = dp[i, j] + 1
                    ans = max(ans, cur_len)
        return ans
