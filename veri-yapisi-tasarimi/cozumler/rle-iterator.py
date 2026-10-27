class RLEIterator:

    def __init__(self, encoding: List[int]):
        self.encoding = encoding

    def next(self, n: int) -> int:
        if self.encoding:
            count = self.encoding[0]
            if count >= n:
                self.encoding[0] -= n
                return self.encoding[1]
            self.encoding = self.encoding[2:]
            return self.next(n - count)
        return -1
