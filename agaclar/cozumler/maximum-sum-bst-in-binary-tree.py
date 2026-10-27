class Solution:

    def maxSumBST(self, root: TreeNode) -> int:
        res = 0

        def traverse(root):
            nonlocal res
            if not root:
                return (1, 0, None, None)
            ls, l, ll, lr = traverse(root.left)
            rs, r, rl, rr = traverse(root.right)
            if (ls == 2 and lr < root.val or ls == 1) and (rs == 2 and rl > root.val or rs == 1):
                size = root.val + l + r
                res = max(res, size)
                return (2, size, ll if ll is not None else root.val, rr if rr is not None else root.val)
            return (0, None, None, None)
        traverse(root)
        return res
