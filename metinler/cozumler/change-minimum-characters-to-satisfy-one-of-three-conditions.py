class Solution:

    def minCharacters(self, a: str, b: str) -> int:
        pa, pb = ([0] * 26, [0] * 26)
        for x in a:
            pa[ord(x) - 97] += 1
        for x in b:
            pb[ord(x) - 97] += 1
        ans = len(a) - max(pa) + len(b) - max(pb)
        for i in range(25):
            pa[i + 1] += pa[i]
            pb[i + 1] += pb[i]
            ans = min(ans, pa[i] + len(b) - pb[i])
            ans = min(ans, len(a) - pa[i] + pb[i])
        return ans
