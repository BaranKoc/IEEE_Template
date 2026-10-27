class Solution:

    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = {node: set() for node in range(numCourses)}
        for pre in prerequisites:
            graph[pre[0]].add(pre[1])

        def path(cur_node, node_b):
            if cur_node == node_b:
                return True
            for neighbor in graph[cur_node]:
                if path(neighbor, node_b):
                    return True
            return False
        ans = []
        for query in queries:
            ans.append(path(query[0], query[1]))
        return ans
