/*
思路：
Flatten Binary Tree to Linked List， 注意是单链表。一开始以为是双链表，浪费不少时间。
用递归，先处理左子树，再处理右子树。节点的右指针指向下一节点。
将左子树的链表插入root与root->right之间！
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
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        if(root->left == NULL) //如果左子树为空，无需插入，直接返回。
            return;
        TreeNode* p_node = root->left;
        while(p_node->right != NULL)
        {
            p_node = p_node->right;
        }
        p_node->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};
