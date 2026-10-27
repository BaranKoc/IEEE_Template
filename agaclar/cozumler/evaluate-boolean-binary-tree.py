class Solution:

    def evaluateTree(self, root: Optional[TreeNode]) -> bool:

        def recur(node):
            if not node.left and (not node.right):
                return True if node.val == 1 else False
            left = recur(node.left)
            right = recur(node.right)
            if node.val == 2:
                return left or right
            if node.val == 3:
                return left and right
        return recur(root)
