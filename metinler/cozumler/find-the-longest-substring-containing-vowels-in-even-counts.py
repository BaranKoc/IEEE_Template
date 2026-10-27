class Solution:

    def findTheLongestSubstring(self, s: str) -> int:
        integrals = [(False, False, False, False, False)]
        mapping = {'a': 0, 'i': 1, 'u': 2, 'e': 3, 'o': 4}
        for v in s:
            vector = list(integrals[-1])
            if v in mapping:
                vector[mapping[v]] = not vector[mapping[v]]
            integrals.append(tuple(vector))
        seen = {}
        res = 0
        for i, v in enumerate(integrals):
            if v in seen:
                res = max(res, i - seen[v])
            else:
                seen[v] = i
        return res
