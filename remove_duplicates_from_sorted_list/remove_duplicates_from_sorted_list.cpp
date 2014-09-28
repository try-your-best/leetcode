/*
简答题，一次A
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* pNode = head;
        while(pNode)
        {
            if(pNode->next != NULL && pNode->val == pNode->next->val)
            {
                ListNode* pTmp =  pNode->next;
                pNode->next = pTmp->next;
                delete pTmp;
            }
            else
            {
                pNode = pNode->next;
            }
        }
        return head;
    }
};
