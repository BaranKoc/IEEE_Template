class Solution:

    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        Task = namedtuple('Task', ['etime', 'ptime', 'index'])
        stasks = sorted([Task(task[0], task[1], i) for i, task in enumerate(tasks)])
        t = i = 0
        heap, result = ([], [])
        while len(result) < len(stasks):
            while i < len(stasks) and stasks[i].etime <= t:
                heappush(heap, (stasks[i].ptime, stasks[i].index))
                i += 1
            if heap:
                ptime, index = heappop(heap)
                result.append(index)
                t += ptime
            else:
                t = stasks[i].etime
        return result
