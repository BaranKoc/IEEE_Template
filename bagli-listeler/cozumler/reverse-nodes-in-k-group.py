class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        res = node = head
        i = 0
        reversedHead, reversedTail = (None, None)
        previousTail = None
        while node:
            if i % k == 0:
                if previousTail:
                    previousTail.next = node
                reversedHead = reversedTail = ListNode(node.val)
            else:
                reversedHead = ListNode(node.val, reversedHead)
            if i % k == k - 1:
                if previousTail:
                    previousTail.next = reversedHead
                previousTail = reversedTail
            if i == k - 1:
                res = reversedHead
            i, node = (i + 1, node.next)
        return res
