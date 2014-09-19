/*
思路：构造两个指针 p_ahead 和 p_behind，p_ahead 指向的链表中第一个下一指针的是值大于x的节点，
p_behind 遍历链表，如果 p_behind->next的值小于x，则移到 p_ahead->next, 然后 p_ahead再向后移（p_ahead=p_ahead->next）
如果p_behind->next的值大于x，则p_behind=p_behind->next;
注意：链表元素交换位置好处是不必移位，但是操作起来麻烦。

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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode dumpy(0);
        dumpy.next = head;
        ListNode *p_ahead =  &dumpy;
        while(p_ahead->next != NULL && p_ahead->next->val < x)
        {
            p_ahead = p_ahead->next;
        }
        ListNode *p_behind = p_ahead->next;
        while(p_behind != NULL)
        {
            if(p_behind->next != NULL && p_behind->next->val < x)
            {
                ListNode *p_tmp = p_ahead->next;
                p_ahead->next = p_behind->next;
                
                p_behind->next = p_behind->next->next;
                
                p_ahead = p_ahead->next;
                p_ahead->next = p_tmp;
            }
            else
            {
                p_behind = p_behind->next;
            }
        }
        return dumpy.next;
    }
};
