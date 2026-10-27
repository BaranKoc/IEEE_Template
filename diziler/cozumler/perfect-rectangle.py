class Solution:

    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        X1, Y1 = (float('inf'), float('inf'))
        X2, Y2 = (-float('inf'), -float('inf'))
        points = set()
        actual_area = 0
        for x1, y1, x2, y2 in rectangles:
            X1, Y1 = (min(X1, x1), min(Y1, y1))
            X2, Y2 = (max(X2, x2), max(Y2, y2))
            actual_area += (x2 - x1) * (y2 - y1)
            for p in [(x1, y1), (x1, y2), (x2, y1), (x2, y2)]:
                if p in points:
                    points.remove(p)
                else:
                    points.add(p)
        expected_area = (X2 - X1) * (Y2 - Y1)
        if actual_area != expected_area:
            return False
        if len(points) != 4:
            return False
        if (X1, Y1) not in points:
            return False
        if (X1, Y2) not in points:
            return False
        if (X2, Y1) not in points:
            return False
        if (X2, Y2) not in points:
            return False
        return True
