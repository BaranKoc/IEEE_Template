class Solution:

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        hrow = {}
        hcol = {}
        hbox = defaultdict(list)
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] not in hrow:
                        hrow[board[i][j]] = 1
                    else:
                        return False
            hrow.clear()
        print('TRUE1')
        for i in range(9):
            for j in range(9):
                if board[j][i] != '.':
                    if board[j][i] not in hcol:
                        hcol[board[j][i]] = 1
                    else:
                        return False
            hcol.clear()
        print('TRUE2')
        for i in range(9):
            for j in range(9):
                i_3 = i // 3
                j_3 = j // 3
                if board[i][j] != '.':
                    if board[i][j] not in hbox[i_3, j_3]:
                        hbox[i_3, j_3] = hbox[i_3, j_3] + [board[i][j]]
                    else:
                        return False
        return True
