#include <algorithm>
#include <cstdint>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace ieee_template {

namespace reverse_linked_list {
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *s=reverseList(head->next);
        ListNode *t=head->next;
            t->next=head;
        head->next=NULL;
        return s;

    }
};
}

}
