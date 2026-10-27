class Solution:

    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        from sortedcontainers import SortedList
        tasks.sort()
        workers.sort()

        def check_valid(ans):
            _tasks = deque(tasks[:ans])
            _workers = workers[-ans:]
            remain_pills = pills
            for worker in _workers:
                task = _tasks[0]
                if worker >= task:
                    _tasks.popleft()
                elif worker + strength >= task and remain_pills:
                    remove_task_idx = bisect.bisect_right(_tasks, worker + strength)
                    del _tasks[remove_task_idx - 1]
                    remain_pills -= 1
                else:
                    return False
            return True
        lo, hi = (0, min(len(workers), len(tasks)))
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if check_valid(mid):
                lo = mid
            else:
                hi = mid - 1
        return lo
