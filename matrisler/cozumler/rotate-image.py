class Solution:

    def rotate(self, matrix: List[List[int]]) -> None:
        size = len(matrix)
        for i in range(size):
            for j in range(i + 1, size):
                matrix[j][i], matrix[i][j] = (matrix[i][j], matrix[j][i])
        print(matrix)
        for row in range(len(matrix)):
            matrix[row] = matrix[row][::-1]
        print(matrix)
