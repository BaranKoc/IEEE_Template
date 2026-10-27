class Solution:

    def minSteps(self, n: int) -> int:
        memo = {}

        def dfs(clipboard_count, screen_count):
            if (clipboard_count, screen_count) in memo:
                return memo[clipboard_count, screen_count]
            if screen_count == n:
                return 0
            if screen_count > n:
                return float('inf')
            copy_opt = paste_opt = float('inf')
            if clipboard_count > 0:
                paste_opt = dfs(clipboard_count, screen_count + clipboard_count)
            if screen_count > clipboard_count:
                copy_opt = dfs(screen_count, screen_count)
            memo[clipboard_count, screen_count] = 1 + min(paste_opt, copy_opt)
            return memo[clipboard_count, screen_count]
        return dfs(0, 1)
