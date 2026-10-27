class Solution:

    def equationsPossible(self, equations: List[str]) -> bool:
        from collections import defaultdict
        g = defaultdict(list)
        for e in equations:
            if e[1] == '=':
                x = e[0]
                y = e[3]
                g[x].append(y)
                g[y].append(x)
        ccs = defaultdict(lambda: -1)

        def dfs(node, cc):
            if node not in ccs:
                ccs[node] = cc
                for neighbour in g[node]:
                    dfs(neighbour, cc)
        for i in range(26):
            dfs(chr(i + 97), i)
        for e in equations:
            if e[1] == '!':
                x = e[0]
                y = e[3]
                if ccs[x] == ccs[y]:
                    return False
        return True
