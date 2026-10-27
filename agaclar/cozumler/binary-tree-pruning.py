class Solution:

    def pruneTree(self, root):
        if not root:
            return root
        root.left, root.right = (self.pruneTree(root.left), self.pruneTree(root.right))
        return None if not root.val and (not root.left) and (not root.right) else root
