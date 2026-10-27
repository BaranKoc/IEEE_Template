class Solution:

    def containVirus(self, mat: List[List[int]]) -> int:
        m, n = (len(mat), len(mat[0]))

        def dfs(i, j, visited, nextInfected):
            if 0 <= i < m and 0 <= j < n and ((i, j) not in visited):
                if mat[i][j] == 2:
                    return 0
                if mat[i][j] == 0:
                    nextInfected.add((i, j))
                    return 1
                else:
                    visited.add((i, j))
                    return dfs(i - 1, j, visited, nextInfected) + dfs(i + 1, j, visited, nextInfected) + dfs(i, j - 1, visited, nextInfected) + dfs(i, j + 1, visited, nextInfected)
            else:
                return 0
        ans = 0
        while True:
            visited = set()
            All_nextinfect = set()
            stop, walls = (set(), 0)
            for i in range(m):
                for j in range(n):
                    if mat[i][j] == 1 and (i, j) not in visited:
                        nextInfected = set()
                        a = dfs(i, j, visited, nextInfected)
                        if len(stop) < len(nextInfected):
                            All_nextinfect = All_nextinfect | stop
                            stop = nextInfected
                            walls = a
                            p, q = (i, j)
                        else:
                            All_nextinfect = All_nextinfect | nextInfected
            if not stop:
                break
            ans += walls

            def fun(p, q):
                if 0 <= p < m and 0 <= q < n and (mat[p][q] == 1):
                    mat[p][q] = 2
                    fun(p + 1, q)
                    fun(p - 1, q)
                    fun(p, q - 1)
                    fun(p, q + 1)
            fun(p, q)
            for a, b in All_nextinfect:
                mat[a][b] = 1
        return ans
