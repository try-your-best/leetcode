/*
一次AC！
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummpy(0);
        ListNode* pNode = &dummpy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                pNode->next = l1;
                l1 = l1->next;
            }
            else
            {
                pNode->next = l2;
                l2 = l2->next;
            }
            pNode = pNode->next;
        }
        if(l1)
        {
           pNode->next = l1; 
        }
        
        if(l2)
        {
           pNode->next = l2;  
        }
        return dummpy.next;
    }
};
