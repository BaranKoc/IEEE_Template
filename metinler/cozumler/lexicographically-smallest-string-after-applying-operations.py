import collections

class Solution:

    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        seen = set()
        deque = collections.deque([s])
        while deque:
            curr = deque.popleft()
            seen.add(curr)
            ad = self.add_(curr, a)
            if ad not in seen:
                deque.append(ad)
                seen.add(ad)
            ro = self.rotate_(curr, b)
            if ro not in seen:
                deque.append(ro)
                seen.add(ro)
        return min(seen)

    def add_(self, s, a):
        res = ''
        for idx, i in enumerate(s):
            if idx % 2 == 1:
                num = (int(i) + a) % 10
                res += str(num)
            else:
                res += i
        return res

    def rotate_(self, s, b):
        idx = len(s) - b
        res = s[idx:] + s[0:idx]
        return res
