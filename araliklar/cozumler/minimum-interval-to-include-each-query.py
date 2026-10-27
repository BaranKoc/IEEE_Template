class Solution:

    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        q = deque(sorted([(x, i) for i, x in enumerate(queries)]))
        ans = [-1] * len(queries)
        ivals = deque(sorted([(a, b, b - a + 1) for a, b in intervals]))
        cands = []
        while q:
            x, i = q.popleft()
            while ivals and x >= ivals[0][0]:
                a, b, c = ivals.popleft()
                if x <= b:
                    heappush(cands, (c, b, a))
            while cands:
                c, b, a = heappop(cands)
                if x <= b:
                    ans[i] = c
                    heappush(cands, (c, b, a))
                    break
        return ans
