class Solution:

    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        ans = [0] * len(queries)
        q = deque(sorted([(size, room, i) for i, (room, size) in enumerate(queries)], key=lambda a: (-a[0], a[1], a[2])))
        rooms = deque(sorted(rooms, key=lambda x: -x[1]))
        cands = []
        while q:
            size, room, i = q.popleft()
            while rooms and rooms[0][1] >= size:
                bisect.insort(cands, rooms.popleft()[0])
            if not cands:
                ans[i] = -1
            else:
                loc = bisect.bisect_left(cands, room)
                if loc == 0:
                    ans[i] = cands[loc]
                elif loc == len(cands):
                    ans[i] = cands[-1]
                else:
                    ans[i] = cands[loc - 1] if room - cands[loc - 1] <= cands[loc] - room else cands[loc]
        return ans
