from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class ClimbingStairs(object):

    def climbStairs(self, n):
        memo = {}
        memo[1] = 1
        memo[2] = 2

        def climb(n):
            if n in memo:
                return memo[n]
            else:
                memo[n] = climb(n - 1) + climb(n - 2)
                return memo[n]
        return climb(n)

class MinCostClimbingStairs:

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cur = 0
        dp0 = cost[0]
        if len(cost) >= 2:
            dp1 = cost[1]
        for i in range(2, len(cost)):
            cur = cost[i] + min(dp0, dp1)
            dp0 = dp1
            dp1 = cur
        return min(dp0, dp1)

class HouseRobber:

    def rob(self, nums: List[int]) -> int:
        rob1 = 0
        rob2 = 0
        for i in nums:
            temp = max(rob1 + i, rob2)
            rob1 = rob2
            rob2 = temp
        return rob2

__all__ = ['ClimbingStairs', 'MinCostClimbingStairs', 'HouseRobber']
