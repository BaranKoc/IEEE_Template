class Solution:

    def minRemoveToMakeValid(self, s):
        stack = []
        split_str = list(s)
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            elif s[i] == ')':
                if len(stack) != 0:
                    stack.pop()
                else:
                    split_str[i] = ''
        for i in stack:
            split_str[i] = ''
        return ''.join(split_str)
