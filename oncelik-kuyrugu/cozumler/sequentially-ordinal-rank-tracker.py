from sortedcontainers import SortedList

class SORTracker:

    def __init__(self):
        self.arr = SortedList()
        self.index = -1

    def add(self, name: str, score: int) -> None:
        self.arr.add([-score, name])

    def get(self) -> str:
        self.index += 1
        return self.arr[self.index][1]
