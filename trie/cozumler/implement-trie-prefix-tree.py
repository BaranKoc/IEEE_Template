class Node:

    def __init__(self):
        self.child = {}
        self.end = False

class Trie:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        sz = len(word)
        temp = self.root
        for ind, i in enumerate(word):
            if i in temp.child.keys():
                temp = temp.child[i]
            else:
                temp.child[i] = Node()
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
