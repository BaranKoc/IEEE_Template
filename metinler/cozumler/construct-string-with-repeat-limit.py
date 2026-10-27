from heapq import heapify, heappush, heappop
from collections import defaultdict

class Solution:

    def repeatLimitedString(self, string: str, k: int) -> str:
        appear, times = (defaultdict(), defaultdict())
        pq, stack = ([], [])
        for s in string:
            appear[s] = appear.get(s, 0) + 1
        for s in appear:
            pq.append((-ord(s), appear[s]))
        heapify(pq)
        appear.clear()
        while pq:
            char, num = heappop(pq)
            s = chr(-char)
            if s in times and times[s] == k:
                if not pq:
                    return ''.join(stack)
                char2, num2 = heappop(pq)
                token = chr(-char2)
                stack.append(token)
                if num2 - 1 > 0:
                    heappush(pq, (char2, num2 - 1))
                heappush(pq, (char, num))
                del times[s]
                times[token] = 1
                continue
            if stack and stack[-1] != s:
                del times[stack[-1]]
            stack.append(s)
            times[s] = times.get(s, 0) + 1
            if num - 1 > 0:
                heappush(pq, (char, num - 1))
        return ''.join(stack)
