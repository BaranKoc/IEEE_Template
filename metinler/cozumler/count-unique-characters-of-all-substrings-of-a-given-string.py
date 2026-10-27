class Solution:

    def uniqueLetterString(self, s: str) -> int:
        ans = 0
        idx_recorder = collections.defaultdict(list)
        n = len(s)
        for idx in range(len(s)):
            c = s[idx]
            idx_recorder[c].append(idx)

        def helper(idxes):
            ans = 0
            for i in range(len(idxes)):
                if i == 0:
                    left = idxes[i] + 1
                else:
                    left = idxes[i] - idxes[i - 1]
                if i == len(idxes) - 1:
                    right = n - idxes[i]
                else:
                    right = idxes[i + 1] - idxes[i]
                ans += left * right
            return ans
        ans = 0
        for c in idx_recorder:
            ans += helper(idx_recorder[c])
        return ans
