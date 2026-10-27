class Solution:

    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        prev = head
        cur = head
        while cur is not None:
            if cur.val == val:
                if cur == head:
                    head = head.next
                    prev = head
                else:
                    prev.next = cur.next
            else:
                prev = cur
            cur = cur.next
        return head
