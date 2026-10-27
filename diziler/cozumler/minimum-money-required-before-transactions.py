class Solution:

    def minimumMoney(self, transactions: list[list[int]]) -> int:
        incomers = [transaction for transaction in transactions if transaction[0] <= transaction[1]]
        outgoers = [transaction for transaction in transactions if transaction[0] > transaction[1]]
        incomers.sort(key=lambda transaction: transaction[0], reverse=True)
        outgoers.sort(key=lambda transaction: transaction[1])
        if outgoers:
            outgoer_cost = sum(map(lambda transaction: transaction[0] - transaction[1], outgoers))
            assert outgoer_cost > 0
            min_ante = outgoer_cost + outgoers[-1][1]
            after_outgoers = min_ante - outgoer_cost
        else:
            min_ante = 0
            after_outgoers = 0
        if incomers:
            min_incomer_available = incomers[0][0]
        else:
            min_incomer_available = 0
        if min_incomer_available > after_outgoers:
            min_ante += min_incomer_available - after_outgoers
        return min_ante
