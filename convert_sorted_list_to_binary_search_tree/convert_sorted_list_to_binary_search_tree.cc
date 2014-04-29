/*
思路：每次取单链表的中点作为当前平衡二叉树子树的根节点，
再以此节点为分界点将链表分为两半，对两部分再递归处理！一次A掉！
时间O(n),空间O(n)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *BuildTreeNode(ListNode *p_node, int list_len)
    {
        if(list_len == 0)
        {
            return NULL;
        }
        int selected_index = list_len/2;
        ListNode *p_cur = p_node;
        for(int i = 0; i < selected_index; i++)
        {
            p_cur = p_cur->next;
        }
        TreeNode *p_tree_node = new TreeNode(p_cur->val);
        p_tree_node->left = BuildTreeNode(p_node,selected_index);
        p_tree_node->right = BuildTreeNode(p_cur->next, list_len-selected_index-1);
        return p_tree_node;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        int list_len = 0;
        ListNode *p_node = head;
        while(p_node != NULL)
        {
            list_len++;
            p_node = p_node->next;
        }
        return BuildTreeNode(head, list_len);
    }
};

