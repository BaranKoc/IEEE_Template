class Solution {
public:

    int getLength(ListNode *head)
    {

        int l = 0;

        while(head != NULL)
        {
            l++;
            head = head->next;
        }
        return l;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *ptr1,*ptr2;

        int length1 = getLength(headA);
        int length2 = getLength(headB);

        int diff = 0;

        if(length1>length2)
        {
            diff = length1-length2;
            ptr1 = headA;
            ptr2 = headB;

        }
        else
        {
            diff = length2 - length1;
            ptr1 = headB;
            ptr2 = headA;
        }

        while(diff)
        {

            ptr1 = ptr1->next;

            if(ptr1 == NULL)
            {
                return NULL;
            }

            diff--;
        }

        while((ptr1 != NULL) && (ptr2 != NULL))
        {

            if(ptr1 == ptr2)
            {
                return ptr1;
            }

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return NULL;

     }
};
