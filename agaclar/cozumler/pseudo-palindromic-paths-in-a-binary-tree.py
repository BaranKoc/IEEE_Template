class Solution:

    def dfs(self, node, path):
        if not node:
            return
        if not node.left and (not node.right):
            path += [node.val]
            d = {}
            for i in path.copy():
                if i in d:
                    del d[i]
                else:
                    d[i] = 1
            self.ans += 1 if len(d) <= 1 else 0
            return
        self.dfs(node.left, path + [node.val])
        self.dfs(node.right, path + [node.val])

    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        self.dfs(root, [])
        return self.ans
