class Solution:

    def characterReplacement(self, s: str, k: int) -> int:
        window_start = 0
        max_length = 0
        max_count = 0
        char_count = {}
        for window_end in range(len(s)):
            char_count[s[window_end]] = char_count.get(s[window_end], 0) + 1
            max_count = max(max_count, char_count[s[window_end]])
            if window_end - window_start + 1 > max_count + k:
                char_count[s[window_start]] -= 1
                window_start += 1
            max_length = max(max_length, window_end - window_start + 1)
        return max_length
