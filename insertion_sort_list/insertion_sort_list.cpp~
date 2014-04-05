/*
实现单向链表的插入排序！
由于单向链表的结构特点，在比较时要从前往后比较！
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
    ListNode *insertionSortList(ListNode *head) {
        if( head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode dump(-1);
        dump.next = head;
        ListNode *p_cur = dump.next;
        while(p_cur != NULL && p_cur->next != NULL)
        {
            ListNode *p_node = &dump;
            bool has_changed = false;
            while(p_node->next != p_cur->next)
            {
                if(p_node->next->val > p_cur->next->val)//因为单向链表，比较时，指针要指向比较值的前一位，以便换位！
                {
                    ListNode *p_tmp = p_cur->next;
                    p_cur->next = p_cur->next->next;//相当于移向下一位

                    p_tmp->next = p_node->next;
                    p_node->next = p_tmp;
                    has_changed = true;
                    break;
                }
                p_node = p_node->next;
            }
            if(!has_changed)
            {
                p_cur = p_cur->next;
            }
        }
        return dump.next;
    }
};
