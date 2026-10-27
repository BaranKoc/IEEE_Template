MAX = 2 ** 31

def consume_tail(current, s):
    target = current[-1] + current[-2]
    if target > MAX:
        return False
    sTarget = str(target)
    if s.find(sTarget) == 0:
        current.append(target)
    else:
        return False
    if sTarget != s:
        return consume_tail(current, s[len(sTarget):])
    return current

class Solution:

    def splitIntoFibonacci(self, num: str) -> List[int]:
        for i in range(len(num)):
            if num[0] == '0' and i > 0:
                break
            first = num[0:i + 1]
            if int(first) > MAX:
                return []
            tail = num[i + 1:]
            for j in range(len(tail)):
                if tail[0] == '0' and j > 0:
                    break
                second = tail[0:j + 1]
                if int(second) > MAX:
                    break
                result = consume_tail([int(first), int(second)], tail[j + 1:])
                if result:
                    return result
        return []
