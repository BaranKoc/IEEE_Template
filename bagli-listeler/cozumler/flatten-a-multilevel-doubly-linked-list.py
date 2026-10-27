class Solution:

    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        node = head
        while node:
            if node.child:
                child = node.child
                while child.next:
                    child = child.next
                child.next = node.next
                if node.next:
                    node.next.prev = child
                node.next = node.child
                node.next.prev = node
                node.child = None
            node = node.next
        return head
