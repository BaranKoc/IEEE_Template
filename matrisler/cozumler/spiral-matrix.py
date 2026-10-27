class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        col, row = (len(matrix[0]), len(matrix))
        l, t, r, b = (0, 0, col - 1, row - 1)
        res = []
        while l <= r and t <= b:
            for i in range(l, r):
                res.append(matrix[t][i])
            for i in range(t, b):
                res.append(matrix[i][r])
            if t == b:
                res.append(matrix[t][r])
            else:
                for i in range(r, l, -1):
                    res.append(matrix[b][i])
            if l == r and t != b:
                res.append(matrix[b][r])
            else:
                for i in range(b, t, -1):
                    res.append(matrix[i][l])
            l += 1
            t += 1
            r -= 1
            b -= 1
        return res
