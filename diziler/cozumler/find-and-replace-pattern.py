class Solution:

    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        d = {}
        for i, v in enumerate(pattern):
            if v in d:
                d[v].append(i)
            else:
                d |= {v: [i]}
        ans = []
        for i in words:
            e = {}
            for j, v in enumerate(i):
                if v in e:
                    e[v].append(j)
                else:
                    e |= {v: [j]}
            for u, v in zip(d.values(), e.values()):
                if u != v:
                    break
            else:
                ans.append(i)
        return ans
