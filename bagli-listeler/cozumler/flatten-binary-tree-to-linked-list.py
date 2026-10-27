class Solution:

    def flatten(self, root: Optional[TreeNode]) -> None:
        prev = None

        def dfs(root):
            nonlocal prev
            if not root:
                return
            dfs(root.right)
            dfs(root.left)
            root.right = prev
            root.left = None
            prev = root
        dfs(root)
