class Solution:

    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        dp = [False for _ in s]
        dp[0] = True
        for i in range(1, len(s)):
            if s[i] == '1':
                continue
            window_start = max(0, i - maxJump)
            window_end = i - minJump
            for j in range(window_start, window_end + 1):
                if dp[j]:
                    dp[i] = True
                    break
        return dp[-1]
