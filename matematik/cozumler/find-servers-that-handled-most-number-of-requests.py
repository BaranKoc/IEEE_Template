class Solution:

    def busiestServers(self, k: int, A: List[int], B: List[int]) -> List[int]:
        available = list(range(k))
        busy = []
        res = [0] * k
        for i, a in enumerate(A):
            while busy and busy[0][0] <= a:
                _, x = heapq.heappop(busy)
                heapq.heappush(available, i + (x - i) % k)
            if available:
                j = heapq.heappop(available) % k
                heapq.heappush(busy, (a + B[i], j))
                res[j] += 1
        a = max(res)
        return [i for i in range(k) if res[i] == a]
