class Solution:

    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        adj_dict = collections.defaultdict(list)
        for u, v in edges:
            if u in restricted or v in restricted:
                continue
            adj_dict[u].append(v)
            adj_dict[v].append(u)
        queue = collections.deque([0])
        visited = {0}
        while queue:
            cur = queue.popleft()
            for neighbor in adj_dict[cur]:
                if neighbor in visited:
                    continue
                visited.add(neighbor)
                queue.append(neighbor)
        return len(visited)
