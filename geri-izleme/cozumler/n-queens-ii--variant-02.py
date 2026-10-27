class Solution:

    def totalNQueens(self, n: int) -> int:
        res = 0
        pdia = set()
        ndia = set()
        col = set()

        def backtrack(r):
            if r == n:
                nonlocal res
                res += 1
                return
            for c in range(n):
                if r + c in pdia or r - c in ndia or c in col:
                    continue
                col.add(c)
                pdia.add(r + c)
                ndia.add(r - c)
                backtrack(r + 1)
                col.remove(c)
                pdia.remove(r + c)
                ndia.remove(r - c)
        backtrack(0)
        return res
