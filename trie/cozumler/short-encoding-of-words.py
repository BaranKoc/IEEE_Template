class Solution:

    def minimumLengthEncoding(self, words):
        trie_root = dict()
        isLeafNode = lambda node: len(node) == 0
        tail_nodes = []
        unique_words = set(words)
        for word in unique_words:
            cur = trie_root
            for char in reversed(word):
                cur[char] = cur.get(char, dict())
                cur = cur[char]
            tail_nodes.append((cur, len(word) + 1))
        return sum((suffix_length for node, suffix_length in tail_nodes if isLeafNode(node)))
