class Solution {
public:
    void deleteNode(ListNode* node) {
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;

        ListNode* delNode = node->next;
        node->next = node->next->next;
        delete delNode;
    }
};
