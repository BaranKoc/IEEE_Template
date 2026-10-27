class Solution:

    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        graph = defaultdict(list)
        for edge in edges:
            graph[edge[0]].append((edge[1], edge[2]))
            graph[edge[1]].append((edge[0], edge[2]))
        q = deque()
        q.append((0, 0, values[0], set([0])))
        cache = {}
        maxPoint = 0
        while q:
            currV, currTime, currPoints, currSet = q.popleft()
            if currV in cache:
                prevTime, prevPoints = cache[currV]
                if prevTime <= currTime and prevPoints > currPoints:
                    continue
            cache[currV] = (currTime, currPoints)
            if currTime > maxTime:
                continue
            if currV == 0:
                maxPoint = max(maxPoint, currPoints)
            for neigh, neighTime in graph[currV]:
                newSet = currSet.copy()
                if neigh not in currSet:
                    newSet.add(neigh)
                    newPoint = currPoints + values[neigh]
                else:
                    newPoint = currPoints
                q.append((neigh, currTime + neighTime, newPoint, newSet))
        return maxPoint
