class Solution:

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        cost = 0
        heap = []
        visited = set([0])
        i = 0
        while len(visited) < len(points):
            for j in range(len(points)):
                if j == i or j in visited:
                    continue
                distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                heapq.heappush(heap, (distance, j))
            while True:
                dist, point = heapq.heappop(heap)
                if point not in visited:
                    cost += dist
                    visited.add(point)
                    i = point
                    break
        return cost
