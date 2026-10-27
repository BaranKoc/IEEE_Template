class Solution:

    def validTicTacToe(self, board: List[str]) -> bool:
        d = {'X': 1, 'O': -1, ' ': 0}
        s = [d[ch] for ch in ''.join(board)]
        sm = sum(s)
        if sm >> 1:
            return False
        n = -3 if sm == 1 else 3
        if n in {s[0] + s[1] + s[2], s[3] + s[4] + s[5], s[6] + s[7] + s[8], s[0] + s[3] + s[6], s[1] + s[4] + s[7], s[2] + s[5] + s[8], s[0] + s[4] + s[8], s[2] + s[4] + s[6]}:
            return False
        return True
