/*
思路：前序遍历。
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
    int maxDepth_;
    int curDepth_;
    void preorder(TreeNode* pNode)
    {
        if(!pNode)
            return;
        ++curDepth_;
        if(!pNode->left && !pNode->right)
        {
            maxDepth_ = max(maxDepth_, curDepth_);
        }
        preorder(pNode->left);
        preorder(pNode->right);
        --curDepth_;
    }
    int maxDepth(TreeNode *root) {
        curDepth_ = 0;
        maxDepth_ = 0;
        preorder(root);
        return maxDepth_;
    }
};
