class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.tree = []

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            self.tree.append(node.val)
            inorder(node.right)
            return
        inorder(self.root)
        self.i = 0

    def next(self) -> int:
        self.i += 1
        return self.tree[self.i - 1]

    def hasNext(self) -> bool:
        return self.i - 1 < len(self.tree) - 1
