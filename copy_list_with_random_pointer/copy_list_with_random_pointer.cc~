/*
思路：现在原链表上复制节点，即把1->2->3 复制成 1->1'>2->2'->3->3。具体操作看剑指题26。
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void CloneNodes(RandomListNode *p_node)
    {
        while(p_node != NULL)
        {
            RandomListNode *p_tmp = new RandomListNode(p_node->label);
            p_tmp->next = p_node->next;
            p_node->next = p_tmp;
            p_node = p_tmp->next;
        }
    }
    void CloneRandom(RandomListNode *p_node)
    {
        while(p_node != NULL)
        {
            if(p_node->random != NULL)
            {
               p_node->next->random =  p_node->random->next;
            }
            p_node = p_node->next->next;
        }
    }
    RandomListNode *BuildNewList(RandomListNode *p_node)
    {
        if(p_node == NULL)
        {
            return NULL;
        }
        RandomListNode *p_new_head = p_node->next;
        p_node->next = p_new_head->next;
        
        RandomListNode *p_new_node = p_new_head;
        while(p_node->next != NULL)
        {
            p_new_node->next = p_node->next->next;//注意，不是p_node->next。
            p_new_node = p_new_node->next;
            p_node = p_node->next;
            p_node->next = p_new_node->next;
        }
        return p_new_head;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        CloneNodes(head);
        CloneRandom(head);
        return BuildNewList(head);
    }
};
