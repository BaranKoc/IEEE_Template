class Solution:

    def smallestSubsequence(self, s: str) -> str:
        last_occurence = {c: i for i, c in enumerate(s)}
        stack = []
        instack = set()
        for i, c in enumerate(s):
            if c not in instack:
                while stack and stack[-1] > c and (last_occurence[stack[-1]] > i):
                    instack.remove(stack[-1])
                    stack.pop()
                instack.add(c)
                stack.append(c)
        return ''.join(stack)
