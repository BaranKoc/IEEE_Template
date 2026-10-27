from sortedcontainers import SortedList

class MKAverage:
    MAX_NUM = 10 ** 5

    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k
        self.sl = SortedList([0] * m)
        self.sum_k = 0
        self.sum_m_k = 0
        self.q = deque([0] * m)

    def addElement(self, num: int) -> None:
        m, k, q, sl = (self.m, self.k, self.q, self.sl)
        q.append(num)
        old = q.popleft()
        r = sl.bisect_right(old)
        if r <= k:
            self.sum_k -= old
            self.sum_k += sl[k]
        if r <= m - k:
            self.sum_m_k -= old
            self.sum_m_k += sl[m - k]
        sl.remove(old)
        r = sl.bisect_right(num)
        if r < k:
            self.sum_k -= sl[k - 1]
            self.sum_k += num
        if r < m - k:
            self.sum_m_k -= sl[m - k - 1]
            self.sum_m_k += num
        sl.add(num)
        return

    def calculateMKAverage(self) -> int:
        if self.sl[0] == 0:
            return -1
        return (self.sum_m_k - self.sum_k) // (self.m - self.k * 2)
