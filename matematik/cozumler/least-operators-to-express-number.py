class Solution(object):

    def leastOpsExpressTarget(self, x, target):
        return self.cost(x, target)

    def cost(self, x, val):
        if val == x:
            return 0
        elif val < x:
            state_1 = 2 * (x - val)
            state_2 = 2 * val - 1
            return min(state_1, state_2)
        else:
            p = int(log(val) // log(x))
            a = x ** p
            b = a * x
            if b < 2 * val:
                return min(p + self.cost(x, val - a), p + 1 + self.cost(x, b - val))
            else:
                return p + self.cost(x, val - a)
