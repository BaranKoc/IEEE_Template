class Solution:

    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        adjList = defaultdict(list)
        for source, target in edges:
            adjList[source].append(target)
            adjList[target].append(source)
        shortest = {}
        queue = deque([(0, 0)])
        seen = set()
        while queue:
            currPos, currDist = queue.popleft()
            if currPos in seen:
                continue
            seen.add(currPos)
            shortest[currPos] = currDist
            for nei in adjList[currPos]:
                queue.append((nei, currDist + 1))
        ans = 0
        for index in range(1, len(patience)):
            resendInterval = patience[index]
            shutOffTime = shortest[index] * 2
            lastSecond = shutOffTime - 1
            lastResentTime = lastSecond // resendInterval * resendInterval
            lastPacketTime = lastResentTime + shutOffTime
            ans = max(lastPacketTime, ans)
        return ans + 1
