class Solution:

    def frequencySort(self, s: str) -> str:
        di = Counter(s)
        heap = []
        heapq.heapify(heap)
        for key, val in di.items():
            heapq.heappush(heap, (-1 * val, key))
        res = ''
        while len(heap):
            val, ch = heapq.heappop(heap)
            res += ch * (-1 * val)
        return res
