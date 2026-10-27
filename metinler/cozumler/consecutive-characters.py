class Solution(object):

    def maxPower(self, s):
        stack = []
        mxpow = 0
        for i in s:
            if stack and stack[-1] != i:
                mxpow = max(mxpow, len(stack))
                stack = []
                stack.append(i)
            else:
                stack.append(i)
        mxpow = max(mxpow, len(stack))
        return mxpow
