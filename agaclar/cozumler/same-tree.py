class Solution:

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = [[p, q]]
        while stack:
            p, q = stack.pop()
            if not p and (not q):
                continue
            elif p and q and (p.val == q.val):
                stack.append([p.left, q.left])
                stack.append([p.right, q.right])
            else:
                return False
        return True
