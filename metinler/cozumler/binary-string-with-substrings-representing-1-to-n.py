class Solution:

    def queryString(self, S: str, N: int) -> bool:
        ans = set()
        for i in range(len(S)):
            for ii in range(i, i + N.bit_length()):
                x = int(S[i:ii + 1], 2)
                if 1 <= x <= N:
                    ans.add(x)
        return len(ans) == N
