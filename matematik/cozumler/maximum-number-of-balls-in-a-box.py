class Solution:

    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        boxes = [0] * 100
        for i in range(lowLimit, highLimit + 1):
            boxes[sum([int(j) for j in str(i)])] += 1
        return max(boxes)
