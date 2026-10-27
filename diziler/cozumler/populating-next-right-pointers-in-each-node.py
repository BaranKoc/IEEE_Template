class Solution:

    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        q = []
        q.append(root)
        if not root:
            return None
        while q:
            prev = None
            for i in range(len(q)):
                node = q.pop(0)
                if prev:
                    prev.next = node
                prev = node
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            prev = None
        return root
