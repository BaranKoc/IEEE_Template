from collections import defaultdict

class Solution:

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        jj = None
        g = defaultdict(lambda: -1)
        k = 0
        hh = head
        while head:
            res = Node(head.val)
            if k == 0:
                jj = res
            if k == 1:
                prev.next = res
            g[head] = res
            prev = res
            k = 1
            head = head.next
        kk = jj
        mm = jj
        while hh:
            if hh.random != None:
                jj.random = g[hh.random]
            else:
                jj.random = None
            hh = hh.next
            jj = jj.next
        kkk = kk
        return kkk
