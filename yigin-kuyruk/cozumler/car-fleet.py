class Solution:

    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        def computeArrivalTime(curr_pos, curr_speed):
            nonlocal target
            return (target - curr_pos) / curr_speed
        cars = list(zip(position, speed))
        cars.sort(key=lambda x: x[0], reverse=True)
        arrival_bound = None
        fleet = 0
        for pos, sp in cars:
            curr_arrival = computeArrivalTime(pos, sp)
            if not arrival_bound or curr_arrival > arrival_bound:
                arrival_bound = curr_arrival
                fleet += 1
        return fleet
