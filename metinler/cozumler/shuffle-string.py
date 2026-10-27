class Solution:

    def restoreString(self, s: str, indices: List[int]) -> str:
        dec = {}
        c = 0
        res = ''
        for i in indices:
            dec[i] = s[c]
            c += 1
        for x in range(len(indices)):
            res += dec[x]
        return res
