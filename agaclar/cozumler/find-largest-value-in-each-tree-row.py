class Solution(object):

    def largestValues(self, root):
        if not root:
            return []
        ans = []
        q = []
        q.append(root)
        while q:
            s = len(q)
            t = []
            for i in range(s):
                n = q.pop(0)
                t.append(n.val)
                if n.left:
                    q.append(n.left)
                if n.right:
                    q.append(n.right)
            ans.append(max(t))
        return ans
