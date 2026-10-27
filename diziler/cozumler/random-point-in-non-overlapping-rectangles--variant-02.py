class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.n_range = list(range(len(self.rects)))
        self.weights = [(x[2] - x[0] + 1) * (x[3] - x[1] + 1) for x in rects]

    def pick(self) -> List[int]:
        rect = self.rects[choices(self.n_range, self.weights, k=1)[0]]
        return [randint(rect[0], rect[2]), randint(rect[1], rect[3])]
