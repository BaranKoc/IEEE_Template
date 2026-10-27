class Solution:

    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        patternMatch = defaultdict(int)
        totalPrisons = 8
        cells = [str(c) for c in cells]
        for d in range(1, n + 1):
            tempCell = []
            tempCell.append('0')
            for c in range(1, totalPrisons - 1):
                if cells[c - 1] == '1' and cells[c + 1] == '1' or (cells[c - 1] == '0' and cells[c + 1] == '0'):
                    tempCell.append('1')
                else:
                    tempCell.append('0')
            tempCell.append('0')
            cells = tempCell
            pattern = ''.join(tempCell)
            if pattern in patternMatch:
                day = patternMatch[pattern]
                remainder = n % (d - 1) - 1
                match = list(patternMatch.keys())[remainder]
                return [int(m) for m in match]
            patternMatch[pattern] = d
        return [int(c) for c in cells]
