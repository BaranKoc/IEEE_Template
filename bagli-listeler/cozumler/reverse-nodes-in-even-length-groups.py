class Solution:

    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        group = 2
        tail = head
        while tail and tail.next:
            cnt = 1
            cur = tail.next
            while cur.next and cnt < group:
                cur = cur.next
                cnt += 1
            pre, cur = (tail, tail.next)
            if cnt % 2 == 0:
                while cnt and cur:
                    nxt = cur.next
                    cur.next = pre
                    pre = cur
                    cur = nxt
                    cnt -= 1
                first = tail.next
                first.next = cur
                tail.next = pre
                tail = first
            else:
                while cnt and cur:
                    pre, cur = (cur, cur.next)
                    cnt -= 1
                tail = pre
            group += 1
        return head
