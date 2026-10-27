from __future__ import annotations

from typing import List, Optional
from collections import Counter, deque
import heapq

class ReverseLinkedList:

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

__all__ = ['ReverseLinkedList']
