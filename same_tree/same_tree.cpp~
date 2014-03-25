/*
思路：先序遍历两棵树，判断两者是否相等。一次A掉。
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
    bool PreorderBothTree(TreeNode *p_node1, TreeNode *p_node2)
    {
        if(p_node1 == NULL || p_node2 == NULL)
        {
            if(p_node1 == NULL && p_node2 == NULL){return true; }
            else {return false; }
        }
        if(p_node1->val != p_node2->val){ return false; }
        bool left = PreorderBothTree(p_node1->left, p_node2->left);
        bool right = PreorderBothTree(p_node1->right, p_node2->right);
        return left && right;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return PreorderBothTree(p, q);
    }
};
