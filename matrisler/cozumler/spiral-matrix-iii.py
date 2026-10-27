class Solution:

    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        ans = [[rStart, cStart]]
        val = 1
        i, j = (rStart, cStart)

        def is_valid(i, j):
            if 0 <= i < rows and 0 <= j < cols:
                return True
            return False
        while True:
            if len(ans) == rows * cols:
                return ans
            for _ in range(val):
                j += 1
                if is_valid(i, j):
                    ans.append([i, j])
            for _ in range(val):
                i += 1
                if is_valid(i, j):
                    ans.append([i, j])
            for _ in range(val + 1):
                j -= 1
                if is_valid(i, j):
                    ans.append([i, j])
            for _ in range(val + 1):
                i -= 1
                if is_valid(i, j):
                    ans.append([i, j])
            val += 2
