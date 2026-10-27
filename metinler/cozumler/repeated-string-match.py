class Solution:

    def repeatedStringMatch(self, A: str, B: str) -> int:
        if len(A) >= len(B):
            if B in A:
                return 1
            elif B in A * 2:
                return 2
            else:
                return -1
        prefix = max(0, B.find(A))
        repeat, postfix = divmod(len(B) - prefix, len(A))
        repeat += bool(prefix) + bool(postfix)
        if B in A * repeat:
            return repeat
        else:
            return -1
