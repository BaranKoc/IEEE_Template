class Solution(object):

    def height(self, root):
        if root is None:
            return 0
        else:
            x, y = (1, 1)
            if root.left:
                x = self.height(root.left) + 1
            if root.right:
                y = self.height(root.right) + 1
            return max(x, y)

    def deepestLeave(self, root, depth):
        if root is None:
            return 0
        if root.left is None and root.right is None:
            if depth == 1:
                return root.val
        return self.deepestLeave(root.left, depth - 1) + self.deepestLeave(root.right, depth - 1)

    def deepestLeavesSum(self, root):
        return self.deepestLeave(root, self.height(root))
