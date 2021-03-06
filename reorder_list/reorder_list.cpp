/*
思路：先遍历链表获得其长度，设为len,然后下标为 (len/2 )+1的节点就是要置前的节点。
这里有先进后出的性质，所以用栈保存节点指针。
因为要使改变的链表末尾的节点为NULL，所以要栈要保存多一位，即下标为 len/2 的节点。
一次A掉。
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
    void reorderList(ListNode *head) {
        if(head == NULL)
            return;
        ListNode *p_node = head;
        int len = 1;
        while(p_node->next != NULL)
        {
            len++;
            p_node = p_node->next;
        }
        stack<ListNode*> nodes;
        //除了存储要置前的节点，还要存储改变后链表的末尾节点，以让其值为NULL
        //末尾节点的下标为 len/2。
        int target_index = len/2; 
        p_node = head;
        int index = 0;
        while(p_node != NULL)
        {
            if(index >= target_index)
            {
                nodes.push(p_node);
            }
            p_node = p_node->next;
            index++;
        }
        p_node = head;
        while(nodes.size() > 1)
        {
            ListNode* p_current = nodes.top();
            nodes.pop();
            p_current->next = p_node->next;
            p_node->next = p_current;
            p_node = p_current->next;
        }
        if(nodes.size() == 1)
        {
            ListNode* p_current = nodes.top();
            nodes.pop();
            p_current->next = NULL;
        }
    }
};
