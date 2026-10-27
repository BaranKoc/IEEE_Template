class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        marked = set()

        def dfs(cell: Tuple[int, int], wp: int) -> bool:
            i = cell[0]
            j = cell[1]
            if wp == len(word):
                return True
            marked.add((i, j))
            neibs = [(i - 1, j), (i, j - 1), (i + 1, j), (i, j + 1)]
            for x, y in neibs:
                if x < 0 or y < 0 or x >= m or (y >= n) or ((x, y) in marked) or (board[x][y] != word[wp]):
                    continue
                if dfs((x, y), wp + 1):
                    return True
            marked.remove((i, j))
            return False
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    if dfs((i, j), 1):
                        return True
        return False
