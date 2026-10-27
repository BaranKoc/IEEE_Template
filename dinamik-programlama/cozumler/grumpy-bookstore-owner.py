class Solution:

    def recursion(self, index, used):
        if index == self.n:
            return 0
        if (index, used) in self.dp:
            return self.dp[index, used]
        choice1 = -float('inf')
        if used == True:
            end = index + self.minutes if index + self.minutes < self.n else self.n
            to_substract = self.prefix_sum[index - 1] if index != 0 else 0
            val = self.prefix_sum[end - 1] - to_substract
            choice1 = self.recursion(end, False) + val
        choice2 = self.recursion(index + 1, used) + (self.customers[index] if self.grumpy[index] == 0 else 0)
        ans = choice1 if choice1 > choice2 else choice2
        self.dp[index, used] = ans
        return ans

    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        self.n = len(customers)
        self.customers = customers
        self.grumpy = grumpy
        self.minutes = minutes
        self.dp = {}
        self.prefix_sum = [x for x in customers]
        for i in range(1, self.n):
            self.prefix_sum[i] += self.prefix_sum[i - 1]
        return self.recursion(0, True)
