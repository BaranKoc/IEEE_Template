class Solution:

    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = deque([(root, 0)])
        res = 0
        while q:
            res = max(res, q[-1][1] - q[0][1] + 1)
            for _ in range(len(q)):
                curr, pos = q.popleft()
                if curr.left:
                    q.append((curr.left, pos * 2))
                if curr.right:
                    q.append((curr.right, pos * 2 + 1))
        return res
