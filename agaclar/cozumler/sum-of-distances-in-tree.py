from typing import List
ROOT_PARENT = -1

class Solution:

    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        g = self.create_undirected_graph(edges, n)
        root = 0
        tree_nodes, distances = ([0] * n, [0] * n)

        def postorder(rt: int, parent: int):
            tree_nodes[rt] = 1
            for c in g[rt]:
                if c != parent:
                    postorder(c, rt)
                    tree_nodes[rt] += tree_nodes[c]
                    distances[rt] += distances[c] + tree_nodes[c]

        def preorder(rt: int, parent: int):
            for c in g[rt]:
                if c != parent:
                    distances[c] = n - tree_nodes[c] + (distances[rt] - tree_nodes[c])
                    preorder(c, rt)
        postorder(root, ROOT_PARENT)
        preorder(root, ROOT_PARENT)
        return distances

    @staticmethod
    def create_undirected_graph(edges: List[List[int]], n: int):
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        return g
