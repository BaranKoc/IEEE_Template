from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class TrieNode:

    def __init__(self):
        self.child = {}
        self.end = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        sz = len(word)
        temp = self.root
        for ind, i in enumerate(word):
            if i in temp.child.keys():
                temp = temp.child[i]
            else:
                temp.child[i] = TrieNode()
                temp = temp.child[i]
            if ind == sz - 1:
                temp.end = True

    def search(self, word: str) -> bool:
        temp = self.root
        for i in word:
            if i in temp.child.keys():
                temp = temp.child[i]
            else:
                return 0
        return temp.end == True

    def startsWith(self, prefix: str) -> bool:
        temp = self.root
        for i in prefix:
            if i in temp.child.keys():
                temp = temp.child[i]
            else:
                return 0
        return 1

__all__ = ['TrieNode', 'Trie']
