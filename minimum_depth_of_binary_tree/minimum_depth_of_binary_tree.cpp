/*
前序遍历，求最低深度。
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
    int minDepth_;
    int curDepth_;
    void preorder(TreeNode* pNode)
    {
        if(!pNode)
            return;
        ++curDepth_;
        if(!pNode->left && !pNode->right)
        {
            minDepth_ = min(minDepth_, curDepth_); //记得不要立即返回，要到末尾减去当前深度！
        }
        if(curDepth_ < minDepth_)
        {
            preorder(pNode->left);
            preorder(pNode->right);
        }
        --curDepth_;
    }
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        curDepth_ = 0;
        minDepth_ = INT_MAX;
        preorder(root);
        return minDepth_;
    }
};
