class Solution:

    def countBinarySubstrings(self, s: str) -> int:
        pre_cont_occ, cur_cont_occ = (0, 1)
        counter = 0
        for idx in range(1, len(s)):
            if s[idx] == s[idx - 1]:
                cur_cont_occ += 1
            else:
                counter += min(pre_cont_occ, cur_cont_occ)
                pre_cont_occ = cur_cont_occ
                cur_cont_occ = 1
        counter += min(pre_cont_occ, cur_cont_occ)
        return counter
