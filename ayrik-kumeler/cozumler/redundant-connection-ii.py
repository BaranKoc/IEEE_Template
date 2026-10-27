class Solution:

    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:

        class DSU:

            def __init__(self, n):
                self.parent = [i for i in range(1005)]

            def find(self, node):
                if self.parent[node] == node:
                    return node
                self.parent[node] = self.find(self.parent[node])
                return self.parent[node]

            def union(self, node1, node2):
                p1 = self.find(node1)
                p2 = self.find(node2)
                if p1 != p2:
                    self.parent[p1] = p2

            def isConnected(self, node1, node2):
                return self.find(node1) == self.find(node2)

        def isValidTree(edges, edge, n):
            d = DSU(n)
            for e in edges:
                if e == edge:
                    continue
                d.union(e[0], e[1])
            return d.isConnected(edge[0], edge[1])
        indegree = []
        count = defaultdict(int)
        for i, j in edges:
            count[j] = count.get(j, 0) + 1
        n = len(edges)
        for i in range(n):
            if count[edges[i][1]] == 2:
                indegree += [i]
        if len(indegree) != 0:
            if isValidTree(edges, edges[indegree[-1]], n):
                return edges[indegree[-1]]
            return edges[indegree[0]]
        else:
            d2 = DSU(n)
            for e in edges:
                if d2.isConnected(e[0], e[1]):
                    return e
                d2.union(e[0], e[1])
