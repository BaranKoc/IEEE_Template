class Solution:

    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:

        def branchAndBound(i: int):
            nonlocal r
            if i == n:
                r = min(r, max(a))
                return
            visited = set()
            for j in range(k):
                if a[j] in visited:
                    continue
                visited.add(a[j])
                if a[j] + jobs[i] >= r:
                    continue
                a[j] += jobs[i]
                branchAndBound(i + 1)
                a[j] -= jobs[i]
        n = len(jobs)
        if n <= k:
            return max(jobs)
        jobs.sort(reverse=True)
        a = list(jobs[:k])
        for job in jobs[k:]:
            m0 = min(a)
            i = a.index(m0)
            a[i] += job
        r = max(a)
        a = [0] * k
        branchAndBound(0)
        return r
