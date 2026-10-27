class Solution:

    def maxDistToClosest(self, seats: List[int]) -> int:
        seat_nums = [ix for ix, val in enumerate(seats) if val == 1]
        left_max, right_max = (min(seat_nums), len(seats) - max(seat_nums) - 1)
        dists = [(y - x) // 2 for x, y in zip(seat_nums, seat_nums[1:])]
        return max([left_max, right_max, *dists])
