class Solution:

    def convertToBase7(self, num: int) -> str:
        if not num:
            return '0'
        sign = num < 0
        num = abs(num)
        stack = []
        while num:
            stack.append(str(num % 7))
            num = num // 7
        return '-' * sign + ''.join(stack[::-1])
