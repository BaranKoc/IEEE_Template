class Solution:

    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n = (len(matrix), len(matrix[0]))
        matrix_sums = [[0 for _ in range(n)] for _ in range(m)]
        for row in range(m):
            for col in range(n):
                if row == 0 and col == 0:
                    matrix_sums[row][col] = matrix[row][col]
                elif row == 0:
                    matrix_sums[row][col] = matrix[row][col] + matrix_sums[row][col - 1]
                elif col == 0:
                    matrix_sums[row][col] = matrix[row][col] + matrix_sums[row - 1][col]
                else:
                    matrix_sums[row][col] = matrix[row][col] + matrix_sums[row][col - 1] + matrix_sums[row - 1][col] - matrix_sums[row - 1][col - 1]
        ans = 0
        for y1 in range(m):
            for x1 in range(n):
                for y2 in range(y1, m):
                    for x2 in range(x1, n):
                        submatrix_total = matrix_sums[y2][x2] - (matrix_sums[y2][x1 - 1] if x1 - 1 >= 0 else 0) - (matrix_sums[y1 - 1][x2] if y1 - 1 >= 0 else 0) + (matrix_sums[y1 - 1][x1 - 1] if y1 - 1 >= 0 and x1 - 1 >= 0 else 0)
                        if submatrix_total == target:
                            ans += 1
        return ans
