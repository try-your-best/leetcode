/*
思路：分块进行翻转！
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
    void reverseList(ListNode** newHead,ListNode** newTail)
    {
        ListNode* pNode = *newHead;
        *newTail = *newHead;
        ListNode* pPre = NULL;
        while(pNode != NULL)
        {
            ListNode* pNext = pNode->next;
            if(pNext == NULL)
            {
                *newHead = pNode;
            }
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummpy(0); //skill
        dummpy.next = head;
        ListNode *bfHead = &dummpy;
        ListNode *nxTail = &dummpy;
        while(nxTail != NULL)
        {
            for(int i = 0; i < k; ++i)
            {
                nxTail = nxTail->next;
                if(nxTail == NULL)
                {
                    return dummpy.next;
                }
            }
            ListNode *tmpHead = bfHead->next;
            ListNode *tmpTail = nxTail;
            nxTail = nxTail->next;
            tmpTail->next= NULL; //在翻转前先将子链表拆分

            reverseList(&tmpHead, &tmpTail);
            
            bfHead->next = tmpHead;//翻转后将子链表拼接
            tmpTail->next = nxTail;

            bfHead = tmpTail;//回归到初始状态
            nxTail = tmpTail;
        }
        return dummpy.next;
    }
};
