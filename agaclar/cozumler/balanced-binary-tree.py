class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def isBalanced(self, root: TreeNode) -> bool:
        res = True

        def dfs(node, i):
            nonlocal res
            if not node:
                return i - 1
            left, right = (dfs(node.left, i + 1), dfs(node.right, i + 1))
            if abs(right - left) > 1:
                res = False
            return max(left, right)
        dfs(root, 0)
        return res
