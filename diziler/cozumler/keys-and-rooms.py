class Solution:

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited_rooms = set()
        queue = collections.deque()
        queue.append(0)
        while queue:
            for _ in range(0, len(queue)):
                room_number = queue.popleft()
                if room_number not in visited_rooms:
                    found_keys = rooms[room_number]
                    for key in found_keys:
                        queue.append(key)
                    visited_rooms.add(room_number)
        if len(visited_rooms) == len(rooms):
            return True
        return False
