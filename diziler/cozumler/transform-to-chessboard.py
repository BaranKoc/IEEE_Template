class Solution(object):

    def movesToChessboard(self, board):
        N = len(board)
        ans = 0
        for count in (collections.Counter(map(tuple, board)), collections.Counter(zip(*board))):
            if len(count) != 2 or sorted(count.values()) != [N / 2, (N + 1) / 2]:
                return -1
            line1, line2 = count
            if not all((x ^ y for x, y in zip(line1, line2))):
                return -1
            starts = [int(line1.count(1) * 2 > N)] if N % 2 else [0, 1]
            ans += min((sum(((x - i) % 2 for i, x in enumerate(line1, start))) for start in starts)) / 2
        return ans
