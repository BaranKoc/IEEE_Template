from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class DisjointSet:

    def __init__(self, size):
        self.parent = [-1 for _ in range(size)]
        self.rank = [-1 for _ in range(size)]

    def find(self, i):
        if self.parent[i] == -1:
            return i
        k = self.find(self.parent[i])
        self.parent[i] = k
        return k

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return -1
        elif self.rank[x] > self.rank[y]:
            self.parent[y] = x
        elif self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.rank[x] += 1
            self.parent[y] = x

__all__ = ['DisjointSet']
