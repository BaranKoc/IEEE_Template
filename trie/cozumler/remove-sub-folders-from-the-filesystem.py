class TrieNode:

    def __init__(self):
        self.children = {}
        self.main = False

class Solution(object):

    def removeSubfolders(self, folder):
        node = TrieNode()
        res = []
        folder.sort()
        for dir in folder:
            name = dir.split('/')
            if self.addTrie(name, node):
                res.append(dir)
        return res

    def addTrie(self, name, node):
        trie = node
        for c in name:
            if c not in trie.children:
                trie.children[c] = TrieNode()
            elif trie.children[c].main == True:
                return False
            trie = trie.children[c]
        trie.main = True
        return True
