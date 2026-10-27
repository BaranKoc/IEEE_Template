class Solution:

    def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
        acc = [0] + [*accumulate(packages)]
        packages.sort()
        ans = float('inf')
        for box in boxes:
            tmp = 0
            box.sort()
            start = 0
            for b in box:
                loc = bisect.bisect(packages, b)
                if loc == 0:
                    continue
                tmp += b * (loc - start) - (acc[loc] - acc[start])
                if loc == len(packages):
                    ans = min(ans, tmp)
                    break
                start = loc
        return ans % (10 ** 9 + 7) if ans != float('inf') else -1
