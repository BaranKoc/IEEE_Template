class Solution:

    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n, m = (len(queries), len(arr))
        answer = [1] * n
        pref = [1] * m
        pref[0] = arr[0]
        if m > 1:
            for i in range(1, m):
                pref[i] = pref[i - 1] ^ arr[i]
        for i, (l, r) in enumerate(queries):
            if l == 0:
                answer[i] = pref[r]
            else:
                answer[i] = pref[r] ^ pref[l - 1]
        return answer
