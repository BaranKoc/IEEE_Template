class Solution:

    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        poss = [(targetSeconds // 60, targetSeconds % 60)]
        if poss[0][0] > 99:
            poss = [(99, poss[0][1] + 60)]
        if poss[0][0] >= 1 and poss[0][1] + 60 <= 99:
            poss.append((poss[0][0] - 1, poss[0][1] + 60))
        costs = list()
        for i in poss:
            curr_start = startAt
            curr_cost = 0
            minutes = str(i[0])
            if i[0] != 0:
                for j in minutes:
                    if int(j) != curr_start:
                        curr_cost += moveCost
                        curr_start = int(j)
                    curr_cost += pushCost
            seconds = str(i[1])
            if len(seconds) == 1 and i[0] != 0:
                seconds = '0' + seconds
            for j in seconds:
                if int(j) != curr_start:
                    curr_cost += moveCost
                    curr_start = int(j)
                curr_cost += pushCost
            costs.append(curr_cost)
        return min(costs)
