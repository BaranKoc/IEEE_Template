from collections import Counter

class Solution:

    def longestSubstring(self, s: str, k: int) -> int:
        return get_longest_substring(s, k)

def get_longest_substring(s, k):
    if len(s) == 0:
        return 0
    c = Counter(s)
    low_freq_char = set([char for char, freq in c.items() if freq < k])
    if len(low_freq_char) == 0:
        return len(s)
    division_points = [i for i in range(len(s)) if s[i] in low_freq_char]
    substr_lst = []
    substr_lst.append(s[:division_points[0]])
    for i in range(len(division_points) - 1):
        substr_lst.append(s[division_points[i] + 1:division_points[i + 1]])
    substr_lst.append(s[division_points[-1] + 1:])
    return max([get_longest_substring(substr, k) for substr in substr_lst])
