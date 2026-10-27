class Solution:

    def countHighestScoreNodes(self, parents: List[int]) -> int:
        graph = collections.defaultdict(list)
        for node, parent in enumerate(parents):
            graph[parent].append(node)
        n = len(parents)
        d = collections.Counter()

        def count_nodes(node):
            p, s = (1, 0)
            for child in graph[node]:
                res = count_nodes(child)
                p *= res
                s += res
            p *= max(1, n - 1 - s)
            d[p] += 1
            return s + 1
        count_nodes(0)
        return d[max(d.keys())]
