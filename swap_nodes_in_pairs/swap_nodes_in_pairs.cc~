/*
简单题目，一次A掉！
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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode dump(-1);//操作要改变链表头的常用招数！
        dump.next = head;
        ListNode *p_first = &dump;
        ListNode *p_second = dump.next;
        while(p_first->next != NULL && p_second->next != NULL)
        {
            p_first->next = p_second->next;
            p_second->next = p_second->next->next;
            p_first->next->next = p_second;
            //move on
            p_first = p_second;
            p_second = p_second->next;
        }
        return dump.next;
    }
};
