from collections import Counter

class Solution:

    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        M = len(matrix)
        N = len(matrix[0])
        colcons = []
        for c in range(N):
            cons = []
            s = 0
            for r in range(M):
                if not matrix[r][c]:
                    s = 0
                else:
                    s += 1
                cons.append(s)
            colcons.append(cons)
        best = 0
        for r in range(M):
            C = Counter((colcons[c][r] for c in range(N)))
            vs = sorted(C.keys(), reverse=True)
            cs = accumulate((C[v] for v in vs))
            for v, c in zip(vs, cs):
                best = max(best, v * c)
        return best
