class Solution:

    def distributeCoins(self, root: Optional[TreeNode]) -> int:

        def dfs(root):
            if not root:
                return (0, 0)
            net_left, left_walk = dfs(root.left)
            net_right, right_walk = dfs(root.right)
            return (net_left + net_right + (root.val - 1), left_walk + right_walk + abs(net_left) + abs(net_right))
        return dfs(root)[1]
