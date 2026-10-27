class Solution:

    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        i = 0
        dummy_head = TreeNode()
        depth = 0
        while i < len(traversal):
            if traversal[i].isdigit():
                value, i = get_value(traversal, i)
                insert_node(dummy_head, depth, value)
            else:
                depth, i = get_depth(traversal, i)
        return dummy_head.left

def get_value(traversal, i):
    value = 0
    while i < len(traversal) and traversal[i].isdigit():
        value *= 10
        value += int(traversal[i])
        i += 1
    return (value, i)

def insert_node(root, depth, value):
    for _ in range(depth):
        if root.right:
            root = root.right
        else:
            root = root.left
    new_node = TreeNode(value)
    if root.left:
        root.right = new_node
    else:
        root.left = new_node

def get_depth(traversal, i):
    depth = 0
    while i < len(traversal) and traversal[i] == '-':
        depth += 1
        i += 1
    return (depth, i)
