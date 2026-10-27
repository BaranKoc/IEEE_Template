class Solution:

    def parseBoolExpr(self, expression: str) -> bool:
        opMap = {'!': '!', '|': '|', '&': '&'}
        expMap = {'t': True, 'f': False}
        expStack = []
        opStack = []
        ans = 0
        i = 0
        while i < len(expression):
            if expression[i] in opMap:
                opStack.append(opMap[expression[i]])
            elif expression[i] in expMap:
                expStack.append(expMap[expression[i]])
            elif expression[i] == '(':
                expStack.append('(')
            elif expression[i] == ')':
                op = opStack.pop()
                ans = []
                while expStack[-1] != '(':
                    if op == '!':
                        ans.append(not expStack.pop())
                    else:
                        ans.append(expStack.pop())
                while len(ans) > 1:
                    if op == '|':
                        exp1, exp2 = (ans.pop(), ans.pop())
                        res = exp1 or exp2
                        ans.append(res)
                    elif op == '&':
                        exp1, exp2 = (ans.pop(), ans.pop())
                        res = exp1 and exp2
                        ans.append(res)
                expStack.pop()
                expStack.append(ans[-1])
            i += 1
        return expStack[-1]
