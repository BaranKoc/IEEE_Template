class Solution:

    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        dp = [0] * len(arr)
        dp[0] = arr[0]
        total = arr[0]
        right = arr[0]
        p = 1
        while p < len(arr):
            dp[p] = max(arr[p], dp[p - 1] + arr[p])
            total += arr[p]
            right = max(right, total)
            p += 1
        isolated = max(dp + [0])
        left = dp[-1]
        if k == 1:
            return isolated % (10 ** 9 + 7)
        return max(left + right + max(0, (k - 2) * total), isolated) % (10 ** 9 + 7)
