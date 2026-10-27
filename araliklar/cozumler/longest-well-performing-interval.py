class Solution:

    def longestWPI(self, hours: List[int]) -> int:
        p = []
        c = 0
        for e in hours:
            if e > 8:
                c += 1
            else:
                c -= 1
            p.append(c)
        a = []
        a1 = []
        for i in range(len(p)):
            a.append([p[i], i])
            a1.append(p[i])
        a1.sort()
        a.sort()
        prefix = []
        currearly = float('inf')
        for t, day in a:
            currearly = min(currearly, day)
            prefix.append(currearly)
        res = 0
        for i in range(len(hours)):
            if p[i] > 0:
                res = max(res, i + 1)
            else:
                loc = bisect_right(a1, -1 + p[i])
                if loc == 0:
                    continue
                else:
                    earliest = prefix[loc - 1]
                    if earliest >= i:
                        continue
                    interval = i - earliest
                    res = max(res, interval)
        return res
