class Solution:

    def cross(self, p, a, b):
        return (a[0] - p[0]) * (b[1] - p[1]) - (a[1] - p[1]) * (b[0] - p[0])

    def _convex_hull_monotone_chain(self, points):
        points = list(sorted(set(points)))
        if len(points) <= 2:
            return points
        lower, upper = ([], [])
        for out, it in ((lower, points), (upper, reversed(points))):
            for p in it:
                while len(out) >= 2 and self.cross(out[-2], out[-1], p) > 0:
                    out.pop()
                out.append(p)
        return lower[:-1] + upper[:-1]

    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        points = [tuple(p) for p in trees]
        ans = set()
        for point in self._convex_hull_monotone_chain(points):
            ans.add(point)
        return ans
