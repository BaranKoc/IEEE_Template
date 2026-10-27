class Solution:

    def countTriplets(self, arr: List[int]) -> int:
        s = [0]
        n = len(arr)
        if n <= 1:
            return 0
        for i in range(n):
            s.append(s[-1] ^ arr[i])
        count = defaultdict(int)
        res = 0
        for i in range(n - 1):
            for k in range(i + 1, n):
                if s[i] == s[k + 1]:
                    res += k - i
        return res
