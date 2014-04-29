/*
思路：复制复杂链表，关键是对random的处理。通过nodes_map构建节点间的映射！
时间O(n),空间O(n);
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
        {
            return head;
        }
        map<RandomListNode*, RandomListNode*> nodes_map;
        RandomListNode *p_new_head = new RandomListNode(head->label);
        nodes_map[head] = p_new_head; //build map
        
        RandomListNode *p_node = head;
        RandomListNode *p_new_node = p_new_head;
        while(p_node->next != NULL)
        {
            p_new_node->next = new RandomListNode(p_node->next->label);
            nodes_map[p_node->next] = p_new_node->next;
            
            p_new_node = p_new_node->next;
            p_node = p_node->next;
        }
        p_node = head;
        while(p_node != NULL)
        {
            if(p_node->random != NULL)
            {
                nodes_map[p_node]->random = nodes_map[p_node->random];
            }
            p_node = p_node->next;
        }
        return p_new_head;
    }
};
