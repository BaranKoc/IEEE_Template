class Solution:

    def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
        if sum(dist) / speed > hoursBefore:
            return -1

        @cache
        def fn(i, k):
            if k < 0:
                return inf
            if i == 0:
                return 0
            return min(ceil((fn(i - 1, k) + dist[i - 1]) / speed) * speed, dist[i - 1] + fn(i - 1, k - 1))
        for k in range(len(dist)):
            if fn(len(dist) - 1, k) + dist[-1] <= hoursBefore * speed:
                return k
