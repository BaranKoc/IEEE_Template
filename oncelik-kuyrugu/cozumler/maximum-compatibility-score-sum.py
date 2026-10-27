import heapq
from collections import defaultdict

class Solution:

    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        m, n = (len(students), len(students[0]))

        def hamming(student, mentor):
            return sum([int(student[i] != mentor[i]) for i in range(n)])
        pq = [(0, 0, '0' * m)]
        optimal = defaultdict(lambda: float('inf'))
        while pq:
            cost, i, mentor_status = heapq.heappop(pq)
            if i == m:
                return m * n - cost
            for j, mentor in enumerate(mentors):
                if mentor_status[j] != '1':
                    new_cost = cost + hamming(students[i], mentor)
                    new_mentor_status = mentor_status[:j] + '1' + mentor_status[j + 1:]
                    if new_cost < optimal[i + 1, new_mentor_status]:
                        optimal[i + 1, new_mentor_status] = new_cost
                        heapq.heappush(pq, (new_cost, i + 1, new_mentor_status))
        return 0
