from graphlib import TopologicalSorter, CycleError
Color = int
Corner = Tuple[int, int]
Rect = Tuple[Corner, Corner]
Layer = Tuple[Color, Rect]

class Solution:

    def isPrintable(self, targetGrid: List[List[int]]) -> bool:

        def compare(a: Layer, b: Layer) -> int:
            val_a, (a_ul, a_lr) = a
            val_b, (b_ul, b_lr) = b
            ul, lr = ((max(a_ul[0], b_ul[0]), max(a_ul[1], b_ul[1])), (min(a_lr[0], b_lr[0]), min(a_lr[1], b_lr[1])))
            if lr[0] - ul[0] <= 0 or lr[1] - ul[1] <= 0:
                return 0
            for r in range(ul[0], lr[0]):
                for c in range(ul[1], lr[1]):
                    if targetGrid[r][c] == val_b:
                        return -1
                    elif targetGrid[r][c] == val_a:
                        return 1
            return 0
        rects: Dict[Color, Rect] = defaultdict(lambda: ([100, 100], [0, 0]))
        for r, row in enumerate(targetGrid):
            for c, val in enumerate(row):
                ul, lr = rects[val]
                rects[val] = ((min(ul[0], r), min(ul[1], c)), (max(lr[0], r + 1), max(lr[1], c + 1)))
        layers: List[Layer] = list(rects.items())
        graph: Dict[Layer, Set[Layer]] = {layer: set() for layer in layers}
        for i, a in enumerate(layers):
            for b in layers[i + 1:]:
                if (cmp := compare(a, b)) < 0:
                    graph[b].add(a)
                elif cmp > 0:
                    graph[a].add(b)
        try:
            grid = [[0] * len(targetGrid[0]) for _ in targetGrid]
            for color, (ul, lr) in TopologicalSorter(graph).static_order():
                for r in range(ul[0], lr[0]):
                    for c in range(ul[1], lr[1]):
                        grid[r][c] = color
        except CycleError:
            return False
        return grid == targetGrid
