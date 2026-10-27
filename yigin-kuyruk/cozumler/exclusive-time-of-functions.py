class Solution:

    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0] * n
        stack = []
        for log in logs:
            log = log.split(':')
            id = int(log[0])
            timestamp = int(log[2])
            state = log[1]
            if state == 'start':
                if stack:
                    res[stack[-1][0]] += timestamp - stack[-1][1]
                stack.append([id, timestamp])
            else:
                res[id] += timestamp - stack.pop()[1] + 1
                if stack:
                    stack[-1][1] = timestamp + 1
        return res
