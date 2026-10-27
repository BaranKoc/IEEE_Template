from collections import deque

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.root = root
        self.parent_keeper = deque([root])
        while True:
            cur = self.parent_keeper[0]
            if cur:
                if cur.left:
                    self.parent_keeper.append(cur.left)
                    if cur.right:
                        self.parent_keeper.append(cur.right)
                        self.parent_keeper.popleft()
                    else:
                        break
                else:
                    break

    def insert(self, v: int) -> int:
        parent = self.parent_keeper[0]
        if not parent.left:
            parent.left = TreeNode(v)
            self.parent_keeper.append(parent.left)
        else:
            parent.right = TreeNode(v)
            self.parent_keeper.append(parent.right)
            self.parent_keeper.popleft()
        return parent.val

    def get_root(self) -> TreeNode:
        return self.root
