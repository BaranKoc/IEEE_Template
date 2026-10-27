class RecentCounter:

    def __init__(self):
        self.store = []

    def ping(self, t: int) -> int:
        self.store.append(t)
        while self.store[0] < t - 3000:
            self.store.pop(0)
        return len(self.store)
