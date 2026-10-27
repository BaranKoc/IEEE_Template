class Solution(object):

    def maxEvents(self, events):
        events = sorted(events, key=lambda x: x[0])
        current_day = 0
        min_heap = []
        event_id = 0
        total_number_of_days = max((end for start, end in events))
        total_events_attended = 0
        for day in range(1, total_number_of_days + 1):
            while event_id < len(events) and events[event_id][0] == day:
                heapq.heappush(min_heap, events[event_id][1])
                event_id += 1
            while min_heap and min_heap[0] < day:
                heapq.heappop(min_heap)
            if min_heap:
                heapq.heappop(min_heap)
                total_events_attended += 1
        return total_events_attended
