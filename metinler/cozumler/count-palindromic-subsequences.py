class Solution:

    def countPalindromes(self, S: str) -> int:
        if len(S) < 5:
            return 0

        def get_pairs(s):
            seen_cnt = {str(num): 0 for num in range(10)}
            seen_cnt[s[0]] = 1
            pair_cnts = defaultdict(int)
            res = [None]
            for idx in range(1, len(s) - 1):
                res.append(pair_cnts.copy())
                for num in seen_cnt.keys():
                    pair_cnts[num, s[idx]] += seen_cnt[num]
                seen_cnt[s[idx]] += 1
            res.append(None)
            return res
        res = 0
        pre, post = (get_pairs(S), get_pairs(S[::-1])[::-1])
        for idx in range(2, len(S) - 2):
            for key, val in pre[idx].items():
                if key in post[idx]:
                    res += post[idx][key] * val
                    res %= 1000000007
        return res
