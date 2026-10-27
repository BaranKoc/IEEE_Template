class Solution:

    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        if not matrix or not matrix[0]:
            return False
        expected = matrix[0]
        expected.pop()
        for row in matrix[1:]:
            if row[1:] != expected:
                return False
            else:
                row.pop()
                expected = row
        return True
