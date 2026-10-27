class Solution:

    def removeInvalidParentheses(self, s: str) -> List[str]:

        def isValid(s):
            stack = []
            for i in range(len(s)):
                if s[i] == '(':
                    stack.append((i, '('))
                elif s[i] == ')':
                    if stack and stack[-1][1] == '(':
                        stack.pop()
                    else:
                        stack.append((i, ')'))
            return (len(stack) == 0, stack)

        def dfs(s, left, right):
            visited.add(s)
            if left == 0 and right == 0 and isValid(s)[0]:
                res.append(s)
            for i, ch in enumerate(s):
                if ch != '(' and ch != ')':
                    continue
                if ch == '(' and left == 0 or (ch == ')' and right == 0):
                    continue
                if s[:i] + s[i + 1:] not in visited:
                    dfs(s[:i] + s[i + 1:], left - (ch == '('), right - (ch == ')'))
        stack = isValid(s)[1]
        lc = sum([1 for val in stack if val[1] == '('])
        rc = len(stack) - lc
        res, visited = ([], set())
        dfs(s, lc, rc)
        return res
