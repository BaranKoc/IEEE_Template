class Solution:

    def generateParenthesis(self, n: int) -> list[str]:
        res = []

        def add(open, close, partialRes):
            nonlocal res
            if open == close == n:
                res.append(''.join(partialRes))
                return
            if close < open:
                add(open, close + 1, partialRes + [')'])
            if open < n:
                add(open + 1, close, partialRes + ['('])
        add(0, 0, [])
        return res
