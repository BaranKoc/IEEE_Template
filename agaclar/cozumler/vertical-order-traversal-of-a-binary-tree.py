class Solution(object):

    def verticalTraversal(self, root):
        q = [(0, 0, root)]
        l = []
        while q:
            col, row, node = q.pop()
            l.append((col, row, node.val))
            if node.left:
                q.append((col - 1, row + 1, node.left))
            if node.right:
                q.append((col + 1, row + 1, node.right))
        l.sort()
        print(l)
        ans = []
        ans.append([l[0][-1]])
        for i in range(1, len(l)):
            if l[i][0] > l[i - 1][0]:
                ans.append([l[i][-1]])
            else:
                ans[-1].append(l[i][-1])
        return ans
