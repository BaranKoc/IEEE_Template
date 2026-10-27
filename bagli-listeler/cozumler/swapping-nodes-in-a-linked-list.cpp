class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);

        dummy -> next = head;

        ListNode* tail = dummy;

        ListNode* curr = head;

        while(k > 1)
        {
            curr = curr -> next;

            k--;
        }

        ListNode* start = curr;

        while(curr)
        {
            tail = tail -> next;

            curr = curr -> next;
        }

        ListNode* end = tail;

        swap(start -> val, end -> val);

        return dummy -> next;
    }
};
