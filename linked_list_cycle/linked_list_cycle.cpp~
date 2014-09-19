/*
链表两指针，一个走两步，一个走一步，如果快追上慢的则存在环！
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* one = head;
        ListNode* two = head;
        two = two->next;
        while(two != NULL)
        {
            if(two == one)
            {
                return true;
            }
            two = two->next;
            if(two == NULL)
            {
                return false;
            }
            two = two->next;
            one = one->next;
        }
        return false;
    }
};
