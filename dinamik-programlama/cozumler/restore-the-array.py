class Solution:

    def num_arrays(self, s, k, memo):
        if not s:
            return 0
        memo_ans = memo.get(s)
        if memo_ans is not None:
            return memo_ans
        num = int(s)
        if num <= k:
            counter = 1
        else:
            counter = 0
        for i in range(len(s) - 1):
            if int(s[:i + 1]) > k:
                break
            if s[i + 1] == '0':
                continue
            counter += self.num_arrays(s[i + 1:], k, memo)
        ans = counter % (10 ** 9 + 7)
        memo[s] = ans
        return ans

    def numberOfArrays(self, s: str, k: int) -> int:
        memo = {}
        return self.num_arrays(s, k, memo)
