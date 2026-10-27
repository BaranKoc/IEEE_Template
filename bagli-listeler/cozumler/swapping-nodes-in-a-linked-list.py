class Solution:

    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        tot = 0
        Head = head
        while Head:
            Head = Head.next
            tot += 1
        one, two = (None, None)
        count = 1
        Head = head
        while Head:
            if one and two:
                break
            if count == k:
                one = Head
            if count == tot - k + 1:
                two = Head
            Head = Head.next
            count += 1
        one.val, two.val = (two.val, one.val)
        return head
