/*
思路：先把要翻转的部分链表拆出来，翻转后在合并进去。

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
    void reverseList(ListNode *pNode)
    {
        ListNode* pPre = NULL;
        while(pNode != NULL)
        {
            ListNode* pNext = pNode->next;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
        ListNode dumpy(0);
        dumpy.next = head;//为了简化对队列头的处理。
        ListNode* preM = &dumpy;
        for(int i = 0; i < m -1; ++i)
            preM = preM->next;
        ListNode* curN = preM;
        for(int i = m-2 ; i < n-1; ++i)
            curN = curN->next;
         ListNode* nextN = curN->next;
         curN->next = NULL;
         ListNode* curM = preM->next;
         preM->next = NULL;
         reverseList(curM);
         preM->next = curN;
         curM->next = nextN;
         return dumpy.next;
    }
};
