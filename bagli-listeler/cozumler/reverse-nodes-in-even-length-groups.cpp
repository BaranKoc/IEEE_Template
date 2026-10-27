class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* prev = NULL;
        while(head) {
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode* dummy = new ListNode();
        dummy -> next = head;

        ListNode* prev = dummy;

        for(int len = 1; len < 1e5 && head; len++) {
            ListNode* tail = head;
            ListNode* nextHead;

            int j = 1;
            while(j < len && tail && tail -> next) {
                tail = tail -> next;
                j++;
            }

            nextHead = tail -> next;

            if((j % 2) == 0) {

                tail -> next = NULL;
                prev -> next = reverseList(head);
                prev = head;
                head -> next = nextHead;
                head = nextHead;
            } else {

                prev = tail;
                head = nextHead;
            }
        }

        return dummy -> next;
    }
};
