class Solution:

    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        result = 1
        freq = {}
        for x in nums:
            if not x % k in freq:
                freq[x % k] = {}
            if not x in freq[x % k]:
                freq[x % k][x] = 0
            freq[x % k][x] += 1
        for fr in freq.values():
            s = sorted([[k, v] for k, v in fr.items()])

            def f(i: int) -> int:
                if i == len(s):
                    return 1
                skip = f(i + 1)
                take = 2 ** s[i][1] - 1
                if i + 1 < len(s) and s[i + 1][0] - s[i][0] == k:
                    take *= f(i + 2)
                else:
                    take *= f(i + 1)
                return skip + take
            result *= f(0)
        return result - 1
