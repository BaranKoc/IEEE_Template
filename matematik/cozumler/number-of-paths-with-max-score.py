class Solution:

    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        h, w = (len(board), len(board[0]))

        @cache
        def visit(i, j):
            if i == h - 1 and j == w - 1:
                return (0, 1)
            elif i >= w or j >= h or board[i][j] == 'X':
                return (0, 0)
            right_score, right_path_count = visit(i, j + 1)
            down_score, down_path_count = visit(i + 1, j)
            diag_score, diag_path_count = visit(i + 1, j + 1)
            max_prevScore = max(right_score, down_score, diag_score)
            cur_path_count = 0
            cur_score = int(board[i][j]) if board[i][j] != 'E' else 0
            if right_score == max_prevScore:
                cur_path_count += right_path_count
            if down_score == max_prevScore:
                cur_path_count += down_path_count
            if diag_score == max_prevScore:
                cur_path_count += diag_path_count
            return (max_prevScore + cur_score, cur_path_count)
        CONST = 10 ** 9 + 7
        maxScore, validPathCount = visit(0, 0)
        return [maxScore % CONST, validPathCount % CONST] if validPathCount else [0, 0]
