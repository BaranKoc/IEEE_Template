class Solution:

    def __init__(self, nums: List[int]):
        self.map = defaultdict(list)
        for i, v in enumerate(nums):
            self.map[v].append(i)

    def pick(self, target: int) -> int:
        return random.sample(self.map[target], 1)[0]
