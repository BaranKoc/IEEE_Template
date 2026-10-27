class Solution:

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:

        def reverse(start, end):
            prev = None
            cur = start
            while prev != end:
                nextNode = cur.next
                cur.next = prev
                prev = cur
                cur = nextNode
            return prev
        if not head or not head.next or right <= left:
            return head
        start, end = (head, head)
        node, afterRight = (0, 0)
        if left == 1:
            inc = left - 1
            while inc > 0:
                start = start.next
                inc -= 1
            inc = right - 1
            while inc > 0:
                end = end.next
                inc -= 1
            afterRight = end.next
            reverse(start, end)
            head = end
        else:
            inc = left - 2
            while inc > 0:
                start = start.next
                inc -= 1
            inc = right - 1
            while inc > 0:
                end = end.next
                inc -= 1
            afterRight = end.next
            begin = start
            start = start.next
            reverse(start, end)
            begin.next = end
        if afterRight:
            start.next = afterRight
        return head
