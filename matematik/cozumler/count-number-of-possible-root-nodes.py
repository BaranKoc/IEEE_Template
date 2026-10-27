class Solution:

    def rootCount(self, edges: List[List[int]], guesses: List[List[int]], k: int) -> int:
        g = [set() for i in range(len(edges) + 1)]
        for e in edges:
            g[e[0]].add(e[1])
            g[e[1]].add(e[0])
        gu = [defaultdict(int) for i in range(len(edges) + 1)]
        for e in guesses:
            gu[e[0]][e[1]] += 1
        mp = defaultdict(int)
        cnt = 0

        def dfs(x, fa, d):
            nonlocal cnt
            mp[d] += 1
            for c in g[x] - {fa}:
                cnt += gu[x][c]
                dfs(c, x, d + gu[c][x] - gu[x][c])
        dfs(0, -1, 0)
        return sum((v * (d + cnt >= k) for d, v in mp.items()))
