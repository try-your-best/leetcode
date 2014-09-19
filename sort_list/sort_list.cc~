/*
思路:复杂度为O(nlog(n))，排序列表。总体思路是归并排序。关键点是找链表的中心点和合并两个有序列表。很容易就AC了。
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
    ListNode *sortList(ListNode *head) {
        if(head == NULL)
        {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        if(p1->next == NULL) //single node
        {
            return p1;
        }
        while(p2->next != NULL)//set middle node to p1
        {
            if(p2->next->next != NULL)
            {
                p2 = p2->next->next;
                p1 = p1->next;
            }
            else
            {
                break;
            }
        }
        p2 = p1->next; // 
        p1->next = NULL;// set the end of first linked list;
        p1 = head;
        p1 = sortList(p1);
        p2 = sortList(p2);
        ListNode dummy(0);//skill!!
        ListNode* pNode = &dummy;
        while(p1 != NULL && p2 != NULL)
        {
            if(p1->val <= p2->val)
            {
                pNode->next = p1;
                p1 = p1->next;
            }
            else
            {
                pNode->next = p2;
                p2 = p2->next;
            }
            pNode = pNode->next;
        }
        if(p1 != NULL)
        {
            pNode->next = p1;
        }
        if(p2 != NULL)
        {
            pNode->next = p2;
        }
        return dummy.next;
    }
};
