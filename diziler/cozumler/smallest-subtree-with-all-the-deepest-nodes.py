class Solution:

    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        deepest_nodes = [0]
        self.find_deepest(root, 0, deepest_nodes)
        targets = set(deepest_nodes[1:])
        return self.find_merge(root, targets)[0]

    def find_deepest(self, node, current_depth, deepest_nodes):
        if not node:
            return
        if current_depth > deepest_nodes[0]:
            deepest_nodes.clear()
            deepest_nodes.append(current_depth)
            deepest_nodes.append(node.val)
        elif current_depth == deepest_nodes[0]:
            deepest_nodes.append(node.val)
        self.find_deepest(node.left, current_depth + 1, deepest_nodes)
        self.find_deepest(node.right, current_depth + 1, deepest_nodes)

    def find_merge(self, node, targets):
        if not node:
            return (None, set())
        found = set()
        if node.val in targets:
            found.add(node.val)
        nleft, left = self.find_merge(node.left, targets)
        if nleft is not None:
            return (nleft, set())
        nright, right = self.find_merge(node.right, targets)
        if nright is not None:
            return (nright, set())
        found = found | left | right
        if not targets - found:
            return (node, set())
        else:
            return (None, found)
