class Solution:

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        p = None
        while head != None:
            temp = head.next
            head.next = p
            p = head
            head = temp
        return p
