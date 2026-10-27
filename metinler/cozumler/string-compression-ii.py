class Solution:

    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        memo = {}

        def f(i, curr_run_ch, run_length, nb_dels_remain):
            if i == len(s):
                return 0
            key = (i, curr_run_ch, run_length, nb_dels_remain)
            if key in memo:
                return memo[key]
            del_ch_cost = float('inf')
            if nb_dels_remain > 0:
                del_ch_cost = f(i + 1, curr_run_ch, run_length, nb_dels_remain - 1)
            keep_ch_cost = 0
            if s[i] == curr_run_ch:
                extra_digit_cost = 0
                if run_length == 1 or len(str(run_length + 1)) > len(str(run_length)):
                    extra_digit_cost = 1
                keep_ch_cost = extra_digit_cost + f(i + 1, curr_run_ch, run_length + 1, nb_dels_remain)
            else:
                keep_ch_cost = 1 + f(i + 1, s[i], 1, nb_dels_remain)
            memo[key] = min(keep_ch_cost, del_ch_cost)
            return memo[key]
        return f(0, '', 0, k)
