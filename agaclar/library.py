from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class TreeDepth(object):

    def maxDepth(self, root):
        result = 0
        depths = []
        self.handler(root, result, depths)
        return max(depths)

    def handler(self, root, result, depths):
        if root:
            result += 1
            self.handler(root.left, result, depths)
            self.handler(root.right, result, depths)
        else:
            depths.append(result)

__all__ = ['TreeDepth']
