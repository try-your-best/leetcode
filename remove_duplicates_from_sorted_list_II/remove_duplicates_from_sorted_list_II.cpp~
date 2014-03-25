/*
思路：使用两个指针指向前后，遍历链表，删除重复元素
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
    void *DeleteNode(ListNode *p_node)//回收被删除的节点
    {
        while(p_node != NULL)
        {
            ListNode *p_current = p_node;
            p_node = p_node->next;
            delete p_current;
        }
    }
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode dummy(0);//构造虚拟节点，简化对链表头的处理
        dummy.next = head;
        ListNode *p_ahead = &dummy;
        ListNode *p_behind = dummy.next;
        while(p_behind != NULL && p_behind->next != NULL) //p_behind != NULL 是为处理链表的末尾为重复元素
        {
            if(p_ahead->next->val != p_behind->next->val) //注意判断的是值
            {
                p_ahead = p_ahead->next;
                p_behind = p_behind->next;
            }
            else
            {   //p_behind->next != NULL 是为处理链表的末尾为重复元素
                while(p_behind->next != NULL && p_ahead->next->val == p_behind->next->val)
                {
                     p_behind = p_behind->next;
                }
                ListNode *p_tmp = p_ahead->next;
                p_ahead->next = p_behind->next;
                p_behind->next = NULL;
                p_behind = p_ahead->next;
                DeleteNode(p_tmp);
            }
        }
        return dummy.next;
    }
};
