from collections import defaultdict

class DetectSquares:

    def __init__(self):
        self.pts = defaultdict(int)
        self.by_x = defaultdict(set)

    def add(self, point: List[int]) -> None:
        self.pts[point[0], point[1]] += 1
        self.by_x[point[0]].add((point[0], point[1]))

    def count(self, p1: List[int]) -> int:
        res = 0
        x1, y1 = (p1[0], p1[1])
        if x1 in self.by_x:
            for p2 in self.by_x[x1]:
                x2, y2 = p2
                if y1 == y2:
                    continue
                b = abs(y1 - y2)
                p3 = (x1 - b, y2)
                p4 = (x1 - b, y1)
                if p3 in self.pts and p4 in self.pts:
                    res += self.pts[p2] * self.pts[p3] * self.pts[p4]
                p3 = (x1 + b, y2)
                p4 = (x1 + b, y1)
                if p3 in self.pts and p4 in self.pts:
                    res += self.pts[p2] * self.pts[p3] * self.pts[p4]
        return res
