/*
思路：依次合并两个有序链表,假设有n个长度为m的链表
时间复杂度 O((n^2)*m),空间复杂度 O(1)
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
    ListNode *MergeTwoLists(ListNode *p_node1, ListNode *p_node2)
    {
        ListNode head(-1);
        for(ListNode* p_current = &head; p_node1 != NULL || p_node2 != NULL; p_current = p_current->next)
        {
            int val1 = p_node1 == NULL ? INT_MAX : p_node1->val;
            int val2 = p_node2 == NULL ? INT_MAX : p_node2->val;
            if(val1 < val2)
            {
                p_current->next = p_node1;
                p_node1 = p_node1->next;
            }
            else
            {
                p_current->next = p_node2;
                p_node2 = p_node2->next;
            }
        }
        return head.next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int lists_size = lists.size();
        if(lists_size == 0)
        {
            return NULL;
        }
        ListNode *p_node = lists[0];
        for(int i = 1; i < lists_size; i++)
        {
            p_node = MergeTwoLists(p_node, lists[i]);
        }
        return p_node;
    }
};
