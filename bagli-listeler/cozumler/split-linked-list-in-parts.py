class Solution:

    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length = 0
        cur = head
        while cur:
            length += 1
            cur = cur.next
        size, extra = (length // k, length % k)
        res = [[] for _ in range(k)]
        prev, cur = (None, head)
        for i in range(k):
            res[i] = cur
            for j in range(size + (1 if extra > 0 else 0)):
                prev, cur = (cur, cur.next)
            if prev:
                prev.next = None
            extra -= 1
        return res
