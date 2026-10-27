class Solution:

    def maxRepOpt1(self, text: str) -> int:
        char_groups = []
        for char, group in groupby(text):
            group_len = len(list(group))
            char_groups.append((char, group_len))
        char_count = Counter(text)
        longest_substr_len = 1
        for char, group_len in char_groups:
            group_len_w_one_addition = min(group_len + 1, char_count[char])
            longest_substr_len = max(longest_substr_len, group_len_w_one_addition)
        for i in range(1, len(char_groups) - 1):
            prev_group_char, prev_group_len = char_groups[i - 1]
            curr_group_char, curr_group_len = char_groups[i]
            next_group_char, next_group_len = char_groups[i + 1]
            if curr_group_len != 1 or prev_group_char != next_group_char:
                continue
            len_after_swapping = min(prev_group_len + next_group_len + 1, char_count[next_group_char])
            longest_substr_len = max(longest_substr_len, len_after_swapping)
        return longest_substr_len
