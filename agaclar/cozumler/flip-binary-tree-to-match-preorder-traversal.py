class Solution:

    def flipMatchVoyage(self, root, voyage):

        def dfs(root):
            if not root:
                return True
            if root.val != voyage[dfs.idx]:
                return False
            dfs.idx += 1
            if root.left and root.left.val != voyage[dfs.idx]:
                root.right and result.append(root.val)
                return dfs(root.right) and dfs(root.left)
            else:
                return dfs(root.left) and dfs(root.right)
        result = []
        dfs.idx = 0
        good = dfs(root)
        return result if good else [-1]
