class Solution(object):

    def __init__(self):
        self.parents = []
        self.count = []

    def makeConnected(self, n, connections):
        if len(connections) < n - 1:
            return -1
        self.parents = [i for i in range(n)]
        self.count = [1 for _ in range(n)]
        for connection in connections:
            a, b = (connection[0], connection[1])
            self.union(a, b)
        return len({self.find(i) for i in range(n)}) - 1

    def find(self, node):
        while node != self.parents[node]:
            node = self.parents[node]
        return node

    def union(self, a, b):
        a_parent, b_parent = (self.find(a), self.find(b))
        a_size, b_size = (self.count[a_parent], self.count[b_parent])
        if a_parent != b_parent:
            if a_size < b_size:
                self.parents[a_parent] = b_parent
                self.count[b_parent] += a_size
            else:
                self.parents[b_parent] = a_parent
                self.count[a_parent] += b_size
