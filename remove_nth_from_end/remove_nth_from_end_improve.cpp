/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//关键点： 
//Given n will always be valid.
//删除节点后，要记得用delete回收内存！！！
//相关题目：返回列表的倒数第N个节点。
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return head;
        ListNode dummy(0);//创建一个新的节点，让算法变得简单。
        dummy.next = head;
        ListNode* p_ahead = &dummy;
        ListNode* p_behind = &dummy;
        for(int i = 0; i < n; i++)
        {
            p_ahead = p_ahead->next;
        }
        while(p_ahead->next != NULL)
        {
            p_ahead = p_ahead->next;
            p_behind = p_behind->next;
        }
        ListNode* tmp = p_behind->next;
        p_behind->next = p_behind->next->next;
        delete tmp;//注意回收垃圾。
        return dummy.next;
    }
};
