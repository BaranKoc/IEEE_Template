from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class FloodFill:

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        queue = deque()
        rows = len(image)
        cols = len(image[0])
        targetColor = image[sr][sc]
        if color == targetColor:
            return image
        rDirs = [1, 0, -1, 0]
        cDirs = [0, 1, 0, -1]
        queue.append((sr, sc))
        while len(queue) > 0:
            r, c = queue.pop()
            image[r][c] = color
            for rd, cd in zip(rDirs, cDirs):
                newRow = r + rd
                newCol = c + cd
                isValidCoordinate = newRow >= 0 and newRow < rows and (newCol >= 0) and (newCol < cols)
                if isValidCoordinate and image[newRow][newCol] == targetColor:
                    queue.append((newRow, newCol))
        return image

class SpiralTraversal:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        col, row = (len(matrix[0]), len(matrix))
        l, t, r, b = (0, 0, col - 1, row - 1)
        res = []
        while l <= r and t <= b:
            for i in range(l, r):
                res.append(matrix[t][i])
            for i in range(t, b):
                res.append(matrix[i][r])
            if t == b:
                res.append(matrix[t][r])
            else:
                for i in range(r, l, -1):
                    res.append(matrix[b][i])
            if l == r and t != b:
                res.append(matrix[b][r])
            else:
                for i in range(b, t, -1):
                    res.append(matrix[i][l])
            l += 1
            t += 1
            r -= 1
            b -= 1
        return res

__all__ = ['FloodFill', 'SpiralTraversal']
