class Solution:

    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        ans = []

        def inorder(node):
            if not node:
                return node
            inorder(node.left)
            ans.append(node.val)
            inorder(node.right)

        def dfs(node):
            if not node:
                return None
            idx = ans.index(node.val)
            node.val = node.val + sum(ans[idx + 1:])
            dfs(node.left)
            dfs(node.right)
        inorder(root)
        dfs(root)
        return root
