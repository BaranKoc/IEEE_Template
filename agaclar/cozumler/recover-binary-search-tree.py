class Solution:

    def inorder(self, root, li):
        if root is None:
            return li
        li = self.inorder(root.left, li)
        li.append(root)
        li = self.inorder(root.right, li)
        return li

    def recoverTree(self, root: TreeNode) -> None:
        li = self.inorder(root, [])
        n = len(li)
        i, j = (1, n - 2)
        a = li[0]
        for i in range(1, n):
            if li[i].val < li[i - 1].val:
                a = li[i - 1]
                break
        b = li[-1]
        for i in range(n - 2, -1, -1):
            if li[i].val > li[i + 1].val:
                b = li[i + 1]
                break
        a.val, b.val = (b.val, a.val)
