class Solution(object):

    def wordBreak(self, s, wordDict):
        dic = defaultdict(list)
        for w in wordDict:
            dic[w[0]].append(w)
        result = []

        def recursion(idx, ans):
            if idx >= len(s):
                result.append(' '.join(ans))
                return
            for w in dic[s[idx]]:
                if s[idx:idx + len(w)] == w:
                    ans.append(w)
                    recursion(idx + len(w), ans)
                    ans.pop()
            return
        recursion(0, [])
        return result
