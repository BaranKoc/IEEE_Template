class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head){

        if(head==NULL || head->next==NULL)
            return head;

        ListNode* newNode=deleteDuplicates(head->next);

        if(head->val==newNode->val)
            return newNode;
        else{
            head->next=newNode;
            return head;
        }
    }
};

class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp =head;
        while(temp->next!=NULL){

            if(temp->val==temp->next->val){
                temp->next=temp->next->next;

            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};
