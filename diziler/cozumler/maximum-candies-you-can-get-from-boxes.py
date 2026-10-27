class Solution:
    count = 0

    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        boxes = []
        progress = False
        for box in initialBoxes:
            if status[box]:
                progress = True
                boxes.extend(containedBoxes[box])
                self.count += candies[box]
                for key in keys[box]:
                    status[key] = 1
            else:
                boxes.append(box)
        if not progress:
            return self.count
        return self.maxCandies(status, candies, keys, containedBoxes, boxes)
