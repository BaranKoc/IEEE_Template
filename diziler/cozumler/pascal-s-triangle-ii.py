class Solution:

    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        if rowIndex == 1:
            return [1, 1]
        prev_prob = self.getRow(rowIndex - 1)
        return [1] + [prev_prob[i] + prev_prob[i - 1] for i in range(1, len(prev_prob))] + [1]
