class Solution:

    def goodNodes(self, root: TreeNode) -> int:
        count = 0

        def helper(node, m):
            nonlocal count
            if not node:
                return
            if node.val >= m:
                count += 1
                m = max(m, node.val)
            helper(node.left, m)
            helper(node.right, m)
        helper(root, root.val)
        return count
