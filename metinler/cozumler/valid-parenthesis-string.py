class Solution:

    def checkValidString(self, s: str) -> bool:
        left, right, star = (deque(), deque(), deque())
        for i, c in enumerate(s):
            if c == '(':
                left.append(i)
            elif c == ')':
                if left and left[-1] < i:
                    left.pop()
                else:
                    right.append(i)
            else:
                star.append(i)
        if not left and (not right):
            return True
        elif not star:
            return False
        l, r = (0, len(star) - 1)
        while l <= r:
            if left:
                if left[-1] < star[r]:
                    left.pop()
                    r -= 1
                else:
                    return False
            if right:
                if right[0] > star[l]:
                    right.popleft()
                    l += 1
                else:
                    return False
            if not left and (not right):
                return True
