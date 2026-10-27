class Solution:

    def allCellsDistOrder(self, rows: int, cols: int, rCenter: int, cCenter: int) -> List[List[int]]:

        def distance(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        matrix = [[i, j] for i in range(rows) for j in range(cols)]
        center = [rCenter, cCenter]
        matrix.sort(key=lambda c: distance(c, center))
        return matrix
