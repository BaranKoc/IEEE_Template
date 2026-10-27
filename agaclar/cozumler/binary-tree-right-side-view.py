class Solution:

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        def dfs(root, d):
            if not root:
                return
            if self.maxi < d:
                self.res.append(root.val)
                self.maxi = d
            dfs(root.right, d + 1)
            dfs(root.left, d + 1)
        self.res, self.maxi = ([], 0)
        dfs(root, 1)
        return self.res
