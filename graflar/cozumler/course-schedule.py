class Solution:

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        pre = {}
        dep = {}
        for p in prerequisites:
            if p[0] not in pre:
                pre[p[0]] = set()
            if p[1] not in dep:
                dep[p[1]] = set()
            pre[p[0]].add(p[1])
            dep[p[1]].add(p[0])
        l = []
        s = set()
        for i in range(numCourses):
            if i not in dep:
                s.add(i)
        while s:
            n = s.pop()
            l.append(n)
            if n in pre:
                for m in pre[n]:
                    dep[m].remove(n)
                    if not dep[m]:
                        s.add(m)
        return len(l) == numCourses
