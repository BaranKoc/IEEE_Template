class Solution:

    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root = ListNode(0, head)
        summ, d, node = (0, {}, root)
        while node:
            summ += node.val
            if summ in d:
                prev = d[summ]
                tmp = prev.next
                tmp_sum = summ
                while tmp != node:
                    tmp_sum += tmp.val
                    if tmp_sum in d and d[tmp_sum] == tmp:
                        d.pop(tmp_sum)
                    tmp = tmp.next
                prev.next = node.next
                node = prev
            else:
                d[summ] = node
            node = node.next
        return root.next
