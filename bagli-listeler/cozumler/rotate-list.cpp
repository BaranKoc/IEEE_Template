class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL){
           return head;
       }
       vector<int> nums;
       ListNode *temp = head;
       while(temp != NULL){
           nums.push_back(temp->val);
           temp = temp->next;
       }

        k = k%nums.size();

     reverse(nums.begin(),nums.end());
     reverse(nums.begin(),nums.begin()+k);
     reverse(nums.begin()+k,nums.end());

 temp = head;
     for(int i = 0; i<nums.size();i++){
         temp->val = nums[i];
         temp = temp->next;
     }
     return head;
    }
};
